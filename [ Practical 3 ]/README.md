# Practical 03: Student Registration Form (HTML5 Forms and Semantic Elements)

**Name:** Manthan Dhale  
**Course:** Tinker Lab (2026–27)  
**Institute:** Symbiosis Institute of Technology, Nagpur  

---

## 1. Aim
To design and develop a structured, accessible student registration form using HTML5 form controls, built-in client-side validation attributes, and semantic HTML5 layout elements.

---

## 2. Theory

### 2.1 HTML5 Semantic Elements for Structure & Forms
Semantic HTML5 tags clearly describe the role of each section to both browsers and assistive technologies (such as screen readers):
- `<header>`, `<main>`, and `<footer>`: Define the top banner, primary form content area, and bottom page footer.
- `<fieldset>` and `<legend>`: Group related form inputs together into logical blocks (e.g., *Personal Information*, *Academic Details*) with a descriptive caption.
- `<label for="...">`: Associates a text label with a specific form control via matching `id` attributes, allowing users to click the label to focus or toggle the input.

### 2.2 HTML5 Form Controls & Input Types
The `<form>` container collects user input and prepares it for submission using `action` and `method` attributes:
- **Specialized `<input>` Types:** `text`, `email`, `tel`, `date`, `number`, `radio` (mutually exclusive choices), and `checkbox` (multiple selections).
- **`<select>` and `<option>`:** Creates a compact dropdown menu for selecting from predefined categories such as engineering branches or academic years.
- **`<textarea>`:** Provides a multi-line text box for longer entries like residential addresses.
- **`<button type="submit">` and `<button type="reset">`:** Submits validated form data or clears all fields back to their default state.

### 2.3 Built-in HTML5 Client-Side Validation
HTML5 performs native input validation in the browser without requiring JavaScript:
- `required`: Prevents form submission if a mandatory field is left blank.
- `type="email"` and `type="tel"`: Verifies proper email formatting (`@` and domain) and numeric phone formats.
- `pattern`: Enforces a regular expression rule (e.g., `pattern="[0-9]{10}"` for a 10-digit mobile number).
- `placeholder`: Displays helpful hint text inside empty fields.

---

## 3. Steps for Implementation
1. Create a folder named `Practical-03-Student-Registration-Form` and create a new file named `registration.html`.
2. Set up the HTML5 boilerplate (`<!DOCTYPE html>`, `<html>`, `<head>`, `<title>`, `<body>`) with semantic `<header>`, `<main>`, and `<footer>` elements.
3. Add a `<form>` element and organize inputs into three semantic groups using `<fieldset>` and `<legend>`: **Personal Details**, **Academic Details**, and **Interests & Address**.
4. Pair every `<input>`, `<select>`, and `<textarea>` with an explicit `<label for="...">` attribute.
5. Apply HTML5 validation attributes (`required`, `pattern`, `min`, `max`, `placeholder`) along with Submit and Reset buttons.
6. Open `registration.html` in a web browser, test both empty/invalid submissions and valid entries, and capture a screenshot (`output.png`).

---

## 4. Files in This Folder
- [`registration.html`](./registration.html) — Complete HTML5 source code for the student registration form.
- [`output.png`](./output.png) — Browser output screenshot *(upload your screenshot with this filename)*.

---

## 5. Source Code (`registration.html`)

```html
<!DOCTYPE html>
<html lang="en">
<head>
  <meta charset="UTF-8">
  <meta name="viewport" content="width=device-width, initial-scale=1.0">
  <title>Practical 03 - Student Registration Form</title>
</head>
<body>

  <header>
    <h1>Student Registration Portal</h1>
    <p>Fill out the form below to register for Tinker Lab &amp; Technical Clubs (2026–27).</p>
  </header>

  <main>
    <form action="#" method="post">

      <fieldset>
        <legend>1. Personal Details</legend>

        <p>
          <label for="fullname">Full Name: *</label><br>
          <input type="text" id="fullname" name="fullname" placeholder="Enter your full name" required>
        </p>

        <p>
          <label for="email">Email Address: *</label><br>
          <input type="email" id="email" name="email" placeholder="student@example.edu" required>
        </p>

        <p>
          <label for="phone">Mobile Number (10 digits): *</label><br>
          <input type="tel" id="phone" name="phone" placeholder="9876543210" pattern="[0-9]{10}" required>
        </p>

        <p>
          <label for="dob">Date of Birth: *</label><br>
          <input type="date" id="dob" name="dob" required>
        </p>

        <p>
          Gender:<br>
          <input type="radio" id="male" name="gender" value="Male" required>
          <label for="male">Male</label>

          <input type="radio" id="female" name="gender" value="Female">
          <label for="female">Female</label>

          <input type="radio" id="other" name="gender" value="Other">
          <label for="other">Other</label>
        </p>
      </fieldset>

      <br>

      <fieldset>
        <legend>2. Academic Information</legend>

        <p>
          <label for="prn">PRN / Roll Number: *</label><br>
          <input type="text" id="prn" name="prn" placeholder="e.g., 26070122001" required>
        </p>

        <p>
          <label for="branch">Department / Branch: *</label><br>
          <select id="branch" name="branch" required>
            <option value="">-- Select Branch --</option>
            <option value="CSE">Computer Science &amp; Engineering (CSE)</option>
            <option value="AI-ML">Artificial Intelligence &amp; Machine Learning</option>
            <option value="ECE">Electronics &amp; Telecommunication</option>
            <option value="MECH">Mechanical Engineering</option>
          </select>
        </p>

        <p>
          <label for="year">Year of Study: *</label><br>
          <input type="number" id="year" name="year" min="1" max="4" value="1" required>
        </p>
      </fieldset>

      <br>

      <fieldset>
        <legend>3. Technical Interests &amp; Address</legend>

        <p>
          Areas of Interest:<br>
          <input type="checkbox" id="web" name="interests" value="Web Development">
          <label for="web">Web Development (HTML/CSS)</label><br>

          <input type="checkbox" id="arduino" name="interests" value="Arduino & IoT">
          <label for="arduino">Arduino &amp; Embedded Systems</label><br>

          <input type="checkbox" id="excel" name="interests" value="Data Analytics">
          <label for="excel">Data Analytics &amp; Excel</label>
        </p>

        <p>
          <label for="address">Residential Address:</label><br>
          <textarea id="address" name="address" rows="4" cols="40" placeholder="Enter your city, state, and pin code..."></textarea>
        </p>
      </fieldset>

      <br>

      <button type="submit">Register Student</button>
      <button type="reset">Clear Form</button>

    </form>
  </main>

  <hr>

  <footer>
    <p>&copy; 2026 Tinker Lab | Department of Computer Science &amp; Engineering</p>
  </footer>

</body>
</html>
