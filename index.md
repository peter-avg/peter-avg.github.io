---
title: Hello World! 👋 
layout: page
---

<div style="display: flex; align-items: center; gap: 30px; flex-wrap: wrap;">

  <div style="flex: 0 0 200px;">
    <img src="assets/me.jpg" alt="Peter Avgerinos" 
         style="width: 180px; border-radius: 50%; box-shadow: 0 4px 8px rgba(0,0,0,0.15);">

  </div>

  <div style="flex: 1; min-width: 250px;">
    <p>My name is <strong>Petros (Peter) Avgerinos</strong> and I am an MSc student at 
    <strong>Imperial College London</strong>, studying Applied Computational Science and Engineering.
    I am currently working towards my thesis, under the supervision of <strong>Professor Rhodri Nelson</strong>
    (Imperial College London) and <strong>Professor Fernando Pereira</strong> (Compilers Lab - UFMG) to reformulate
    the Sparsity Propagation Analysis (SPA) Pass, as a static analysis within the MLIR Framework.</p>

    <p>My undergraduate degree was a 5-year diploma in Electrical and Computer Engineering 
    from the <strong>National Technical University of Athens (NTUA)</strong>. After graduating from NTUA in 2024, 
    I joined the Institute of Communication and Computer Systems (ICCS) as a research associate,
    working on a variety of projects related to the responsible development and deployment of trustworthy AI systems.</p>

  <p>You can view my CV 
  <a href="assets/Petros Avgerinos CV.pdf" target="_blank" style="color: #0073b1; text-decoration: underline;"> here </a>.
  </p>
  </div>

</div>

## Interests

I am currently drawn to the use of Compiler Infrastructure, such as <strong>LLVM and MLIR</strong>,
for optimizing Compilers and  Domain Specific Languages (DSLs), particularly in the space of modelling and simulation.
Some questions that are fascinating to me include: 
1. How can we exploit tensor sparsity to transform a computational graph statically through a compiler pass?
2. How can we exploit different rounding modes, such as Stochastic Rounding, to minimize the upper bound of the error in a numerical application, through the compiler?
3. Can we statically infer about the correctness of a numerical solver that runs on a cluster, based on its properties and some weak memory model?

I am also particularly interested in the combination of DSLs and Large Language Models (LLMs) for solving complex
issues such as transforming ambiguous requirements to applications and enabling abstract thinking in LLMs.

I am currently involved in a personal research project that aims to create an expressive 
DSL to efficiently allow for the interpretation of Abstraction and Reasoning Corpus (ARC) images as code, 
by humans and LLMs. You can find more about this on the [Erminia](/erminia/index.md) project page.
Please feel free to reach out if you would like to discuss this project or collaborate!
