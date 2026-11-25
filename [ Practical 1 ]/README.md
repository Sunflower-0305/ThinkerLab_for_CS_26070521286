# Practical 01: Introduction to HTML (Text Formatting, Lists, and Tables)


**Name:** Manthan Dhale  
**Course:** Tinker Lab (2026–27)  
**Institute:** Symbiosis Institute of Technology, Nagpur  


---


## 1. Aim
To understand the basic structure of an HTML5 document and create a webpage demonstrating text formatting tags, ordered/unordered/description lists, and structured tables[span_0](start_span)[span_0](end_span).


---


## 2. Theory


### 2.1 HTML Document Structure
**HTML (HyperText Markup Language)** is the standard markup language used to structure content on the web. Every HTML5 webpage follows a standard hierarchical skeleton:
<!DOCTYPE html>: Declares the document type and HTML5 version to the browser.
<html>: The root element wrapping all page content.
<head>: Contains metadata, character encoding (<meta charset="UTF-8">), and the browser tab <title>.
<body>: Contains all visible webpage content rendered in the browser window.
### 2.2 Text Formatting Tags
HTML provides semantic and visual inline tags to emphasize and style text:
<strong> / <b>: Renders **bold** text (with semantic importance for <strong>).
<em> / <i>: Renders italicized text (with semantic stress for <em>).
<u> and <mark>: Underlines text and highlights key terms with a background color.
<sub> and <sup>: Formats subscript (e.g., $\text{H}_2\text{O}$) and superscript (e.g., $x^2$) characters.
<del> and <ins>: Indicates deleted (strikethrough) and newly inserted text.
### 2.3 HTML Lists
Lists organize related items cleanly:
**Unordered List (<ul>):** Displays bulleted items using <li> (list item) tags when sequence does not matter.
**Ordered List (<ol>):** Displays numbered or lettered items (type="1", "A", "i") for sequential steps or rankings.
**Description List (<dl>):** Pairs terms (<dt>) with their definitions (<dd>).
### 2.4 HTML Tables
Tables arrange multi-variable data into rows and columns:
<table>: Defines the table container.
<thead> and <tbody>: Group header rows separately from body data rows.
<tr>: Defines a table row.
<th>: Defines a bold, centered table header cell.
<td>: Defines a standard table data cell (supports colspan and rowspan for merging cells).
---


## 3. Steps for Implementation
1. Create a project folder named Practical-01-HTML-Basics and open a new file named index.html in VS Code (or any text editor).
2. Add the standard HTML5 boilerplate (<!DOCTYPE html>, <html>, <head>, <title>, and <body>).
3. Create a title heading (<h1>) and an introductory paragraph demonstrating text formatting tags (<strong>, <em>, <mark>, <u>, <sub>, <sup>).
4. Add an unordered list (<ul>) of core web technologies and an ordered list (<ol>) outlining webpage creation steps.
5. Build a structured lab schedule using <table>, <thead>, <tbody>, <tr>, <th>, and <td> with visible borders and cell padding.
6. Save index.html, open it in a web browser to verify all tags render properly, and capture a screenshot (output.png) for documentation.


---


## 4. Files in This Folder
[index.html](./index.html) — Complete HTML5 source code for Practical 01.
[output.png](./output.png) — Browser output screenshot (upload your screenshot with this filename).
---




</body>
</html>
