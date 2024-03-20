---
title: 테마 사용법
sidebar: themeUsage_sidebar
permalink: themeUsage_landing_page.html
folder: themeUsage
summary: 이 블로그에서 사용하는 테마 사용법에 대해서 기술합니다. 
---

## 사이드바 생성

`NewSideBar` 라는 이름의 Sidebar를 새로 생성합니다.

### 1. _config.yml 수정

`_config.yml` 에서 `sidebars:` 를 찾아 새 사이드바의 이름을 추가합니다.

```
sidebars:
- NewSideBar
```

### 2. NewSideBar_sidebar.yml 파일 생성

`_data/sidebars/NewSideBar_sidebar.yml` 파일을 생성하고 내용을 적절하게 입력합니다.

```
entries:
- title: sidebar
  product: Sample Product
  folders:

  - title:
    output: pdf
    type: frontmatter
    folderitems:
    - title:
      url: /titlepage.html
      output: pdf
      type: frontmatter
    - title:
      url: /tocpage.html
      output: pdf
      type: frontmatter

  - title: Overview
    output: web, pdf
    folderitems:

    - title: Get started
      url: /NewSideBar_landing_page.html
      output: web, pdf
      type: homepage
```

## 페이지 생성

`NewPage` 라는 이름의 Pages를 새로 생성합니다.

### 1. pages 폴더에 NewPage 라는



### 