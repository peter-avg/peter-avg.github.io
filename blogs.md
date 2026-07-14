---
title: Blog
layout: page
permalink: /blog/
---

<div class="content-narrow">

{% if site.posts.size == 0 %}
  <p>No posts yet. Check back soon!</p>
{% else %}
  {% for post in site.posts %}
  <div class="post-entry">
    <h2>
      <a href="{{ post.url | relative_url }}">{{ post.title }}</a>
    </h2>
    <p class="post-date">
      {{ post.date | date: "%B %-d, %Y" }}
      {% if post.tags.size > 0 %}
        &nbsp;&middot;&nbsp;
        {% for tag in post.tags %}<span class="tag">{{ tag }}</span>{% endfor %}
      {% endif %}
    </p>
    {% if post.excerpt %}
    <p class="post-excerpt">{{ post.excerpt | strip_html | truncatewords: 40 }}</p>
    {% endif %}
    <a href="{{ post.url | relative_url }}" class="read-more">Read more &rarr;</a>
  </div>
  {% endfor %}
{% endif %}

</div>
