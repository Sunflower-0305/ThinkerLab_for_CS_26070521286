# Practical 02: Educational Website (Hyperlinks, Images, and Navigation Elements)

**Name:** Manthan Dhale  
**Course:** Tinker Lab (2026–27)  
**Institute:** Symbiosis Institute of Technology, Nagpur  

---

## 1. Aim
To design and develop a multi-section educational webpage using HTML5 that demonstrates internal and external hyperlinks, embedded images with accessibility attributes, and structured navigation elements.

---

## 2. Theory

### 2.1 Hyperlinks (`<a>` Anchor Tag)
The HTML anchor tag (`<a>`) creates clickable hyperlinks that connect web pages, sections, or external resources using the `href` (Hypertext Reference) attribute:
- **External Links:** Point to another website using a full URL (`href="https://example.com"`), often paired with `target="_blank"` and `rel="noopener noreferrer"` to open safely in a new tab.
- **Internal / Relative Links:** Navigate between pages inside the same website folder (e.g., `href="courses.html"`).
- **Bookmark (Fragment) Links:** Jump to a specific section on the same page using an element's `id` attribute (e.g., `href="#courses"` jumps to `<section id="courses">`).
- **Email & Telephone Links:** Trigger default mail or call apps via `mailto:` and `tel:` schemes.

### 2.2 Embedding Images (`<img>` Tag)
The self-closing `<img>` element embeds graphics into a webpage:
- `src`: Specifies the relative path or URL of the image file (e.g., `./images/campus.jpg`).
- `alt`: Provides descriptive alternative text for screen readers and displays if the image fails to load.
- `width` / `height`: Controls rendered image dimensions while preserving aspect ratio.
- `<figure>` and `<figcaption>`: Semantic HTML5 containers used to group an image with its visible caption.

### 2.3 Navigation Elements (`<nav>`)
The semantic `<nav>` element defines the primary navigation block of a website. Grouping anchor links inside an unordered list (`<ul>` and `<li>`) inside `<nav>` creates a clean, accessible menu structure that screen readers and search engines recognize as site navigation.

---

## 3. Steps for Implementation
1. Create a folder named `Practical-02-Educational-Website` with a subfolder `images/` for storing campus/course graphics.
2. Create `index.html` with the standard HTML5 document structure (`<!DOCTYPE html>`, `<html>`, `<head>`, `<title>`, `<body>`).
3. Build a top navigation menu using `<nav>` and `<ul>` containing internal section links (`#about`, `#courses`, `#resources`, `#contact`).
4. Add an educational overview section (`<section id="about">`) featuring a campus/banner image inside `<figure>` with `src`, `alt`, and `<figcaption>`.
5. Create a courses section (`<section id="courses">`) and an external learning resources section (`<section id="resources">`) using `target="_blank"` links to official documentation (e.g., MDN Web Docs, W3Schools, NPTEL).
6. Add a footer with a `mailto:` contact link and a "Back to Top" bookmark link (`href="#top"`), then test all links and images in a browser.

---

## 4. Files in This Folder
- [`index.html`](./index.html) — Complete HTML5 source code for the educational webpage.
- `images/` — Folder containing embedded webpage images (e.g., `campus.jpg`).
- [`output.png`](./output.png) — Browser output screenshot *(upload your screenshot with this filename)*.

---

## 5. Source Code (`index.html`)

```html
