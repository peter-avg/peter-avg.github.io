---
title: "Stochastic Rounding: Part 1, an overview"
date: 2026-05-05
layout: post
tags: [meta]
---

Hello, thanks for popping by!


## How a failed PhD interview led to a new exploration into science

So, I'll jump straight to the point. I failed my first PhD interview. I was well prepared,
had done some mock interviews before hand, I even skipped lunch to get that extra edge
everyone keeps talking about with fasting and all. I was confident that I had gotten in!
And then I didn't.

I blasted through the first round by showcasing my excitement about science and engineering, 
and really presenting evidence of idependent work. I feel like these two points are very
important if you're interested in applying to PhDs.

For the second round, I was tasked with presenting a paper out of three options that were provided.
I chose a paper by Croci et al. called: [Stochastic Rounding: Implementation, Error Analysis, and Applications](https://eprints.maths.manchester.ac.uk/2843/1/cfhm22.pdf).
As I was reading this thing, I started to make a lot of connections between stuff that I've already seen
and things that are important in the space of High Performance Computing (HPC) and Artificial Intelligence
(AI) infrastructure. This idea of using probability to zero out the error in the unit roundoff was so elegant,
and paired well with many other concepts such as quantization and mixed precision. And so I become very interested, 
and as I found out recently at the EuroLLVM 2026 developers meeting, so is every vendor in the space of AI infra.

## Stochastic Rounding, a quick, and hopefully potent explanation

So what is Stochastic Rounding you ask. I've been flaunting this term in your face, acting all smart, but it's 
really a very simple and elegant really tid bit that can make a huge difference in various applications within 
scientific computing.

Let's take an example of a vector inner product. So an element-wise multiplication that collapses to a sum looks like this: $\mathbf{u}, \mathbf{v} \in \mathbb{R}^n$.

Now there is a reason why a phrase it that way, 


                                                                                                                                                                                                                                                           
$$s = \langle \mathbf{u}, \mathbf{v} \rangle = \sum_{i=1}^{n} u_i v_i$$                                                                                                                                                                                  
                                                                                                                                                                                                                                                    
When computing this in finite precision (say, float16 or bfloat16), each multiplication and addition is subject to rounding. Let $u$ denote the **unit roundoff** — the maximum relative error introduced by a single rounding operation. Under **ro
und to nearest (RTN)**, each product $u_i v_i$ is replaced by a rounded value $\hat{p}_i$ with error:                                                                                                                                               
                                                                                                                                                                                                                                                    
$$\hat{p}_i = u_i v_i + \epsilon_i, \qquad |\epsilon_i| \leq u \cdot |u_i v_i|$$                                                                                                                                                                    
                                                                                                                                                                                                                                                    
These errors are deterministic and can align. When we accumulate $n$ such terms, the total error can grow linearly with $n$:                                                                                                                        
                                                                                                                                                                                                                                                    
$$|\hat{s} - s| \leq (n-1)\, u \sum_{i=1}^{n} |u_i v_i|$$                                                                                                                                                                                           
                                                                                                                                                                                                                                                    
Under **stochastic rounding (SR)**, each value $x$ is rounded to one of its two nearest floating-point neighbours randomly, with probability proportional to proximity:                                                                             
                                                                                                                                                                                                                                                    
$$\text{SR}(x) = \begin{cases} \lfloor x \rfloor & \text{with probability } \dfrac{\lceil x \rceil - x}{\lceil x \rceil - \lfloor x \rfloor} \\[6pt] \lceil x \rceil & \text{with probability } \dfrac{x - \lfloor x \rfloor}{\lceil x \rceil - \lfl
oor x \rfloor} \end{cases}$$                                                                                                                                                                                                                        
                                                                                                                                                                                                                                                    
The key property is that $\mathbb{E}[\text{SR}(x)] = x$ — stochastic rounding is **unbiased**. The rounding errors $\epsilon_i = \text{SR}(u_i v_i) - u_i v_i$ behave like zero-mean random variables, so by the law of large numbers they tend to c
ancel rather than pile up. The expected accumulated error over $n$ terms grows only as $\sqrt{n}$:                                                                                                                                                  
                                                                                                                                                                                                                                                    
$$\mathbb{E}[|\hat{s} - s|] = O\!\left(\sqrt{n}\, u\right) \cdot \|\mathbf{u}\|_2 \|\mathbf{v}\|_2$$                                                                                                                                                
                                                                                                                                                                                                                                                    
Compared to $O(n\, u)$ for RTN, this is a meaningful improvement at scale — exactly the kind of thing that matters when you're summing millions of terms in a neural network forward pass.                                                          
                                                                                                                                                                                            

