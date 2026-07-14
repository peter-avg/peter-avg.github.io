---
title: Projects
layout: page
permalink: /projects/
---

<div class="carousel">
  <button class="carousel-btn carousel-prev" type="button" aria-label="Previous project">
    <svg width="20" height="20" viewBox="0 0 24 24" fill="none" stroke="currentColor" stroke-width="2" stroke-linecap="round" stroke-linejoin="round"><polyline points="15 18 9 12 15 6"></polyline></svg>
  </button>

  <div class="carousel-track">

    <div class="card">
      <img src="/assets/hello.gif" alt="Alan Compiler">
      <h3><a href="https://github.com/peter-avg/Alan-Compiler">Alan Compiler</a></h3>
      <p>A compiler for the Alan Programming Language in C++14, using Flex for lexical analysis, Bison for
  parsing tokens into syntactically valid constructs and LLVM for generating optimized bytecode across multiple target
  architectures.</p>
    </div>

    <div class="card">
      <img src="/assets/CF.gif" alt="Image Processing">
      <h3>Krager</h3>
      <p>A unified C++ command-line image processing library addressing 2D spatial filtering, 3D volume projections, and slicing operations.
      This project implements core computational algorithms from scratch. This includes bespoke median-finding algorithms,
      custom convolution spatial loops, and manual memory management for large 3D datasets, ensuring a deep understanding of algorithmic complexity and software sustainability.</p>
    </div>

    <div class="card">
      <img src="/assets/demet_full_ensemble.png" alt="DEMET">
      <h3><a href="https://github.com/peter-avg/DEMET">DEMET</a></h3>
      <p>DEMET, or Dementia Explainable Transformer, is a cognitive assessment agent that serves as a pre-diagnostic tool in clinical practice.</p>
    </div>

    <div class="card">
      <img src="/assets/logo.png" alt="BlockChat">
      <h3><a href="https://github.com/peter-avg/BlockChat">BlockChat</a></h3>
      <p>Welcome to BlockChat, a comprehensive blockchain application built entirely in Golang. This application showcases a decentralized blockchain system with CLI and Webapp interfaces, allowing users to join the blockchain network, send messages or Bitcoin, and engage in transactions with the assurance of a Proof of Stake validation mechanism.</p>
    </div>

    <div class="card">
      <img src="/assets/logo-2.png" alt="BePresent">
      <h3><a href="https://github.com/peter-avg/BePresentApp">BePresent</a></h3>
      <p>A full-stack mobile application to NOT use your phone while with friends. Enjoy life, Be Present.</p>
    </div>

    <div class="card">
      <img src="/assets/DI.jpg" alt="DeepImpact Shuvalov et. al, 2017">
      <h3>DeepImpact</h3>
      <p>The Deepimpact package provides an integrated toolchain for modelling atmospheric entry events and assessing their ground-level consequences for the UK (as default). It combines an airburst modelling with fast geospatial lookup and mapping utilities, enabling end-to-end analysis—from asteroid entry physics to postcode-level damage estimation.</p>
    </div>

  </div>

  <button class="carousel-btn carousel-next" type="button" aria-label="Next project">
    <svg width="20" height="20" viewBox="0 0 24 24" fill="none" stroke="currentColor" stroke-width="2" stroke-linecap="round" stroke-linejoin="round"><polyline points="9 18 15 12 9 6"></polyline></svg>
  </button>
</div>

<script>
  (function () {
    var track = document.querySelector('.carousel-track');
    var prev = document.querySelector('.carousel-prev');
    var next = document.querySelector('.carousel-next');
    if (!track || !prev || !next) return;

    function step() {
      var card = track.querySelector('.card');
      if (!card) return track.clientWidth;
      var gap = parseFloat(getComputedStyle(track).columnGap || 20);
      return card.getBoundingClientRect().width + gap;
    }

    function updateButtons() {
      var maxScroll = track.scrollWidth - track.clientWidth - 1;
      prev.disabled = track.scrollLeft <= 2;
      next.disabled = track.scrollLeft >= maxScroll;
    }

    prev.addEventListener('click', function () {
      track.scrollBy({ left: -step(), behavior: 'smooth' });
    });
    next.addEventListener('click', function () {
      track.scrollBy({ left: step(), behavior: 'smooth' });
    });
    track.addEventListener('scroll', updateButtons);
    window.addEventListener('resize', updateButtons);
    updateButtons();
  })();
</script>
