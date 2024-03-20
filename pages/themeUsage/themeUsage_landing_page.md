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

```yaml
sidebars:
- NewSideBar
```

### 2. NewSideBar_sidebar.yml 파일 생성

`_data/sidebars/NewSideBar_sidebar.yml` 파일을 생성하고 내용을 적절하게 입력합니다.

```yaml
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

### 1. 폴더 생성

`pages/NewPage` 폴더를 생성합니다.

### 2. 소개 페이지 생성

`pages/NewPage/NewPage_landing_page.md` 를 작성하고 내용을 적절히 채워 넣습니다. 사이드바 생성에 관련해선 여기를 참조합니다.

```
---
title: Overview
sidebar: NewPage_sidebar
permalink: NewPage_landing_page.html
folder: NewPage
summary: Test content summary 
---

## Header 2

Example Contnet
```

### 3. topnav.yml 수정

`_data/topnav_yml` 에 새로 생성한 페이지를 적절한 위치에 추가합니다.

```yaml
    - title: Products
      folderitems:
        - title: NewPage
          url: /NewPage_landing_page.html
```

### 4. home_sidebar.yml 수정

`_data/sidebars/home_sidebar.yml` 에 새로 생성한 페이지를 적절한 위치에 추가합니다.

```yaml
entries:
- title: Sidebar
  levels: one
  folders:

  - title: Products
    output: web
    folderitems:
    - title: NewPage
      url: /NewPage_landing_page.html
      output: web
```