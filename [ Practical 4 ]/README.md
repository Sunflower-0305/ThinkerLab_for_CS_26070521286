# Practical 04: Responsive Webpage using CSS (Inline, Internal, External CSS, Flexbox, and Media Queries)

**Name:** Manthan Dhale  
**Course:** Tinker Lab (2026–27)  
**Institute:** Symbiosis Institute of Technology, Nagpur  

---

## 1. Aim
To design and develop a responsive webpage using HTML5 and CSS3 that demonstrates the three methods of applying CSS (inline, internal, and external), modern layout alignment using CSS Flexbox, and adaptive screen resizing using CSS Media Queries.

---

## 2. Theory

### 2.1 Three Ways to Apply CSS
**CSS (Cascading Style Sheets)** controls the visual presentation, colors, typography, and layout of HTML documents. It can be applied in three ways following the cascade priority order (Inline > Internal > External):
- **Inline CSS:** Applied directly to a single HTML element via the `style="..."` attribute. Useful for quick, one-off overrides, though not scalable for large pages.
- **Internal (Embedded) CSS:** Defined inside a `<style>` tag within the `<head>` section of an HTML document. Ideal for single-page specific styling rules.
- **External CSS:** Stored in a separate `.css` file (e.g., `style.css`) and linked via `<link rel="stylesheet" href="style.css">`. This is the industry standard for maintainability across multi-page websites.

### 2.2 CSS Flexbox Layout
**CSS Flexible Box Layout (`display: flex`)** is a one-dimensional layout model designed to distribute space and align items cleanly inside a container, even when item sizes are dynamic:
- `flex-direction`: Controls the main axis (`row` or `column`).
- `justify-content`: Aligns items along the main horizontal axis (`space-between`, `center`, `space-around`).
- `align-items`: Aligns items along the cross vertical axis (`center`, `stretch`, `flex-start`).
- `flex-wrap: wrap` & `gap`: Allows flex cards to wrap onto new lines cleanly with consistent spacing.

### 2.3 Responsive Web Design & Media Queries
**Responsive Web Design (RWD)** ensures a webpage adapts smoothly across desktops, tablets, and smartphones without horizontal scrolling:
- **Viewport Meta Tag:** `<meta name="viewport" content="width=device-width, initial-scale=1.0">` instructs mobile browsers to match the screen's logical width.
- **Media Queries (`@media`):** Apply conditional CSS rules based on viewport breakpoints (e.g., `@media (max-width: 768px)`), stacking horizontal navigation bars and multi-column card grids vertically on smaller screens.

---

## 3. Steps for Implementation
1. Create a folder named `Practical-04-Responsive-CSS-Webpage` containing `index.html` and `style.css`.
2. Link `style.css` inside the `<head>` of `index.html` using `<link rel="stylesheet" href="style.css">` (**External CSS**), and add page-specific banner rules inside a `<style>` tag (**Internal CSS**).
3. Apply an **Inline CSS** highlight style (`style="..."`) to an announcement badge inside the hero section.
4. Build a responsive navigation header and a three-card feature section in `style.css` using `display: flex`, `justify-content: space-between`, `flex-wrap: wrap`, and `gap`.
5. Add a `@media (max-width: 768px)` media query in `style.css` to stack the navigation links and feature cards vertically on mobile screens.
6. Open `index.html` in a web browser, test desktop and mobile views using Browser Developer Tools (`F12` → Toggle Device Toolbar), and capture screenshots (`output_desktop.png` and `output_mobile.png`).

---

## 4. Files in This Folder
- [`index.html`](./index.html) — HTML5 webpage structure demonstrating inline and internal CSS.
- [`style.css`](./style.css) — External stylesheet containing Flexbox layouts and responsive media queries.
- [`output_desktop.png`](./output_desktop.png) — Desktop browser view screenshot *(upload your screenshot with this filename)*.
- [`output_mobile.png`](./output_mobile.png) — Mobile responsive view screenshot *(upload your screenshot with this filename)*.

---

## 5. Source Code

### 5.1 `index.html`
```html
<!DOCTYPE html>
<html lang="en">
<head>
  <meta charset="UTF-8">
  <meta name="viewport" content="width=device-width, initial-scale=1.0">
  <title>Practical 04 - Responsive CSS Webpage</title>

  <!-- External CSS -->
  <link rel="stylesheet" href="style.css">

  <!-- Internal CSS -->
  <style>
    .hero-banner {
      background: linear-gradient(135deg, #1e293b, #0f172a);
      color: #ffffff;
      text-align: center;
      padding: 60px 20px;
    }
    .hero-banner h1 {
      font-size: 2.5rem;
      margin-bottom: 12px;
    }
  </style>
</head>
<body>

  <!-- Responsive Flexbox Navbar -->
  <header class="navbar">
    <div class="logo">TinkerLab.</div>
    <nav>
      <ul class="nav-links">
        <li><a href="#home">Home</a></li>
        <li><a href="#modules">Modules</a></li>
        <li><a href="#about">About</a></li>
        <li><a href="#contact">Contact</a></li>
      </ul>
    </nav>
  </header>

  <!-- Hero Section with Internal & Inline CSS -->
  <section id="home" class="hero-banner">
    <span style="background-color: #eab308; color: #0f172a; padding: 5px 12px; border-radius: 20px; font-weight: bold; font-size: 0.85rem;">
      INLINE CSS BADGE &bull; CSS3 &amp; FLEXBOX
    </span>
    <h1>Responsive Web Design</h1>
    <p>Adaptive layouts built with Inline, Internal, External CSS, Flexbox, and Media Queries.</p>
  </section>

  <!-- Flexbox Responsive Card Section -->
  <main id="modules" class="container">
    <h2 class="section-title">Core CSS Concepts Demonstrated</h2>
    <div class="card-grid">
      <article class="card">
        <h3>1. Cascading Styles</h3>
        <p>Combines inline attributes, internal <code>&lt;style&gt;</code> blocks, and an external <code>style.css</code> sheet cleanly.</p>
      </article>
      <article class="card">
        <h3>2. Flexbox Alignment</h3>
        <p>Uses <code>display: flex</code>, <code>justify-content</code>, and <code>flex-wrap</code> for balanced horizontal and vertical alignment.</p>
      </article>
      <article class="card">
        <h3>3. Media Queries</h3>
        <p>Automatically adapts typography, navigation bars, and multi-column grids for mobile screens below 768px.</p>
      </article>
    </div>
  </main>

  <footer id="contact" class="footer">
    <p>&copy; 2026 Manthan Dhale | Tinker Lab Practical 04</p>
  </footer>

</body>
</html>
