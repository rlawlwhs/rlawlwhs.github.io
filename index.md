---
layout: default
title: 홈
---

블로그

{% assign grouped_posts = site.posts | group_by_exp: "post", "post.path | split: '/' | slice: 0, post.path | split: '/' | size | minus: 1 | join: '/'" %}

{% for group in grouped_posts %}
  <h2>📂 {{ group.name }}</h2>
  <ul>
    {% for post in group.items %}
      <li>
        <a href="{{ post.url }}">{{ post.title }}</a>
        <small>({{ post.date | date: "%Y-%m-%d" }})</small>
      </li>
    {% endfor %}
  </ul>
{% endfor %}
