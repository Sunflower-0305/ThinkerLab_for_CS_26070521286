# Manthan Vijay Dhale — Personal Portfolio

A responsive, multi-page portfolio starter built with plain HTML, CSS and JavaScript. No framework or build step is required.

## Pages included

- `index.html` — Home page with introduction, featured-work cards and calls to action.
- `about.html` — About section, editable skills and journey timeline, plus a profile-photo uploader.
- `certificates.html` — Certificate gallery with image/PDF upload, preview, open and remove actions.
- `contact.html` — Contact form with browser validation and an email-app handoff.

## Run the website

1. Extract the project folder.
2. Open `index.html` in a modern browser, or open the folder in Visual Studio Code and use the Live Server extension.
3. Use the top navigation to move between pages.

## Personalise the content

- Search for `Manthan Vijay Dhale` in the HTML files if you need to change the display name.
- Replace the introduction and sample project cards in `index.html` with your own details.
- Edit your biography, education/journey timeline and skill tags in `about.html`.
- On the About page, select **Upload your photo** to preview and save your portrait in this browser. You can also replace `assets/images/avatar-placeholder.svg` with your own image file and update the image path in `about.html`.
- On the Certificates page, select **Add certificates** to add JPG, PNG, WebP or PDF files. You can preview/open and remove them.
- Replace the sample Instagram, LinkedIn and GitHub links in `contact.html` with your profile URLs.

## Make the contact form send to you

Open `assets/js/main.js` and replace:

```js
const CONTACT_EMAIL = 'YOUR_EMAIL@example.com';
```

with your real email address. The form validates the fields and opens the visitor's default email app with a pre-filled message. This is a front-end-only solution; it does not send or store messages on a server. For a hosted form that submits without opening an email app, connect a form service or backend.

## Important note about uploads

The photo and certificate upload tools save files in the visitor's browser using IndexedDB. That is useful for trying out the page and managing your own gallery on your device, but uploads are **not automatically published to the internet** and are not shared with other visitors. To show certificate files to everyone on your hosted site, place the files inside the website folder (for example, `assets/images/certificates/`) and add their image paths to the gallery HTML, or connect a server-side upload/storage service.

## Design and accessibility

- Responsive layout for desktop, tablet and mobile.
- Collapsible mobile navigation with an active-page indicator.
- Semantic page landmarks, form labels, keyboard-focus states and reduced-motion support.
- Google Fonts are loaded online; system fallbacks are provided by CSS.
