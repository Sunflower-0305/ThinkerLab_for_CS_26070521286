# Value-Added Experiment 02: Student Performance Analytics Dashboard in Microsoft Excel

**Name:** Manthan Dhale  
**Course:** Tinker Lab (2026–27)  
**Institute:** Symbiosis Institute of Technology, Nagpur  

---

## 1. Aim
To design and build an automated Student Performance Analytics Dashboard in Microsoft Excel using dynamic formulas, lookup/conditional functions, data validation rules, conditional formatting, and interactive charts to analyze and visualize academic performance data[cite: 9].

---

## 2. Theory

### 2.1 Dynamic Formulas & Analytical Functions
Automated dashboards eliminate manual recalculation by linking summary metrics directly to structured student score tables:
- **Aggregate & Statistical Functions:** `SUM()`, `AVERAGE()`, `MAX()`, `MIN()`, and `COUNTA()` calculate total marks, subject averages, highest/lowest scores, and total student counts.
- **Nested `IF()` & `IFS()` Logic:** Evaluates multi-tier grading criteria (e.g., `O`, `A+`, `A`, `B`, `C`, `F`) and determines overall `Pass` / `Fail` status automatically.
- **Conditional Aggregation (`COUNTIF`, `COUNTIFS`, `AVERAGEIF`, `SUMIF`):** Computes grade distributions, subject-wise pass counts, and attendance-linked averages dynamically.
- **Lookup Functions (`VLOOKUP` / `XLOOKUP` / `INDEX-MATCH`):** Enables an interactive **Individual Student Lookup Card** on the dashboard where selecting a Roll Number/PRN automatically pulls that student's marks, percentage, rank, and status.

### 2.2 Data Validation
**Data Validation** (**Data → Data Validation**) enforces data integrity at entry and powers interactive dashboard controls:
- **Whole Number / Decimal Constraints:** Restricts subject mark entries to valid bounds (`0` to `100`), displaying custom error alerts if out-of-range values are entered.
- **Dropdown Lists (`List` Validation):** Creates clean dropdown selectors (such as selecting a `Student ID` or `Subject` on the dashboard) to dynamically update lookup metrics without editing formulas.

### 2.3 Conditional Formatting
**Conditional Formatting** (**Home → Conditional Formatting**) applies dynamic visual cues based on cell values:
- **Highlight Cell Rules:** Colors `Pass` cells green and `Fail` or low-attendance (`< 75%`) cells red for immediate risk identification.
- **Data Bars & Color Scales:** Renders inline progress bars proportional to total percentage and heatmaps across subject columns to highlight top performers and weak areas at a glance.
- **Icon Sets:** Displays directional arrows or status indicators next to performance benchmarks.

### 2.4 Interactive Charts & Dashboard Design
An effective analytics dashboard separates **Raw Data** (`Student_Data` sheet) from **Visual Presentation** (`Dashboard` sheet):
- **KPI Summary Cards:** Display headline metrics (Total Students, Class Average %, Overall Pass Rate %, Top Scorer) at the top of the dashboard.
- **Comparative & Distribution Charts:** Combines **Clustered Column/Bar Charts** (subject-wise average comparison), **Doughnut/Pie Charts** (grade distribution and Pass/Fail ratio), and **Combo Charts** (attendance vs. marks trend) styled with consistent colors and zero clutter.

---

## 3. Steps for Implementation
1. Open Microsoft Excel and create a workbook named `student_performance_dashboard.xlsx` with two dedicated worksheets: `Student_Data` (backend dataset) and `Dashboard` (executive visual view).
2. In `Student_Data`, enter student records (`PRN`, `Student Name`, `Subject 1–5 Marks`, and `Attendance %`) and convert the range into an **Excel Table** (`Ctrl + T`).
3. Apply **Data Validation** (**Data → Data Validation**) to all subject columns (`Whole Number` between `0` and `100`) and attendance (`0%` to `100%`) with an error alert message to prevent invalid data entry.
4. Add calculated columns using `=SUM()`, `=AVERAGE()`, `=RANK.EQ()`, and nested `=IF()` formulas to compute Total Marks, Percentage, Grade, Class Rank, and `Pass / Fail` result automatically.
5. Apply **Conditional Formatting** to the `Percentage` column (Data Bars), `Result` column (`Pass` = Green, `Fail` = Red), and `Attendance %` column (highlight values `< 75%`).
6. On the `Dashboard` sheet, build KPI summary cards using `COUNTIF`, `AVERAGE`, and `MAX`, plus an interactive **Student Scorecard Lookup** driven by a Data Validation dropdown list and `VLOOKUP` / `INDEX-MATCH` formulas.
7. Insert **Subject Average Column Charts**, a **Grade Distribution Doughnut Chart**, and a **Pass vs. Fail Pie Chart**, align them neatly into a grid layout (hiding gridlines via **View → Gridlines**), and capture a screenshot (`output.png`).

---

## 4. Files in This Folder
- [`student_performance_dashboard.xlsx`](./student_performance_dashboard.xlsx) — Complete Excel workbook with raw data, formulas, data validation, conditional formatting, and interactive dashboard.
- [`student_performance_dashboard.pdf`](./student_performance_dashboard.pdf) — PDF export of the dashboard for direct in-browser viewing on GitHub *(recommended)*.
- [`output.png`](./output.png) — Screenshot preview of the completed Excel dashboard *(upload your screenshot with this filename)*.

---

## 5. Dashboard Architecture & Formula Summary

| Dashboard Component | Excel Feature / Formula Used | Function & Analytical Output |
| :--- | :--- | :--- |
| **Input Guardrails** | **Data Validation** (`0–100` Whole Number) | Prevents invalid marks or out-of-bounds entries |
| **Totals & Percentage** | `=SUM(D2:H2)`, `=AVERAGE(D2:H2)` | Auto-calculates student aggregate and percentage |
| **Automated Grading** | Nested `=IF()` / `=IFS()` & `=RANK.EQ()` | Assigns letter grades (`O`, `A+`, `A`, `B`, `F`) and class rank |
| **Visual Alerts** | **Conditional Formatting** (Data Bars & Highlight Rules) | Flags failing grades (`< 40`) and low attendance (`< 75%`) in red |
| **KPI Summary Cards** | `=COUNTA()`, `=COUNTIF()`, `=MAX()` | Displays Total Students, Pass %, Class Average, and Top Score |
| **Interactive Lookup** | **Data Validation List** + `=VLOOKUP(...)` | Dynamically fetches any selected student's complete report card |
| **Visual Analytics** | **Column, Pie & Doughnut Charts** | Compares subject-wise averages and overall grade distribution |

---

## 6. Dashboard Preview
![Value-Added Experiment 02 Excel Dashboard Preview](./output.png)

---

## 7. Observation
- Data Validation rules immediately blocked invalid mark entries outside `0–100`, keeping downstream averages and charts accurate.
- Conditional Formatting visually separated high-scoring students from at-risk students (`Fail` or `< 75%` attendance) without manual inspection.
- Selecting different student IDs from the Data Validation dropdown dynamically updated the lookup card, and modifying any score in `Student_Data` automatically refreshed all KPIs and charts on the `Dashboard` tab.

---

## 8. Conclusion
In this value-added experiment, an automated Student Performance Analytics Dashboard was successfully developed in Microsoft Excel using dynamic formulas, data validation, conditional formatting, and interactive charts[cite: 9]. Separating structured backend tables from a visual KPI and chart layer creates a scalable, error-resistant reporting tool for academic performance tracking.
