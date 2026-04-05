---
title: Blog
layout: page
permalink: /blog/
---

<div style="max-width: 700px; margin: 0 auto;">

{% if site.posts.size == 0 %}
  <p>No posts yet. Check back soon!</p>
{% else %}
  {% for post in site.posts %}
  <div style="border-bottom: 1px solid #eee; padding: 20px 0;">
    <h2 style="margin-bottom: 5px;">
      <a href="{{ post.url | relative_url }}" style="text-decoration: none; color: inherit;">{{ post.title }}</a>
    </h2>
    <p style="color: #888; font-size: 0.9em; margin: 0 0 10px 0;">
      {{ post.date | date: "%B %-d, %Y" }}
      {% if post.tags.size > 0 %}
        &nbsp;&middot;&nbsp;
        {% for tag in post.tags %}<span style="background: #f0f0f0; border-radius: 4px; padding: 2px 8px; margin-right: 4px; font-size: 0.85em;">{{ tag }}</span>{% endfor %}
      {% endif %}
    </p>
    {% if post.excerpt %}
    <p style="margin: 0; color: #444;">{{ post.excerpt | strip_html | truncatewords: 40 }}</p>
    {% endif %}
    <a href="{{ post.url | relative_url }}" style="font-size: 0.9em; color: #0073b1;">Read more &rarr;</a>
  </div>
  {% endfor %}
{% endif %}

</div>
