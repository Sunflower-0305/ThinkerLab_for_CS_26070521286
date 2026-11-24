# Practical 06: Data Analysis and Reporting in Microsoft Excel

**Name:** Manthan Dhale  
**Course:** Tinker Lab (2026–27)  
**Institute:** Symbiosis Institute of Technology, Nagpur  

---

## 1. Aim
To perform structured data analysis and visual reporting in Microsoft Excel using formulas, built-in functions, multi-level sorting, filtering, charts, and Pivot Tables.

---

## 2. Theory

### 2.1 Formulas, Cell Referencing & Core Functions
Excel formulas begin with an equal sign (`=`) and dynamically recalculate results whenever underlying cell values change:
- **Cell Referencing:**
  - **Relative (`A2`):** Adjusts automatically when copied across rows or columns.
  - **Absolute (`$A$2`):** Locks both row and column coordinates, essential for fixed tax rates, thresholds, or lookup tables.
  - **Mixed (`$A2` or `A$2`):** Locks either the column or the row.
- **Aggregate Functions:** `SUM()`, `AVERAGE()`, `MIN()`, `MAX()`, `COUNT()`, and `COUNTA()` summarize numerical and non-empty ranges.
- **Logical & Conditional Functions:** `IF()` evaluates true/false conditions, while `COUNTIF()`, `SUMIF()`, and `AVERAGEIF()` compute metrics based on specified criteria.
- **Lookup Functions:** `VLOOKUP()` and `INDEX-MATCH` retrieve matching records from structured reference tables.

### 2.2 Sorting & Filtering Data
- **Sorting:** Arranges records in ascending (`A–Z`, smallest to largest) or descending (`Z–A`, largest to smallest) order. **Custom Multi-Level Sort** prioritizes a primary column (e.g., Department) and then sorts secondary tie-breakers (e.g., Total Score or Sales).
- **Filtering:** Using **Data → Filter** (`Ctrl + Shift + L`) or converting a range into an **Excel Table** (`Ctrl + T`) adds dropdown controls to filter records by specific text, numeric thresholds (`Greater Than`, `Top 10`), or date ranges without deleting hidden rows.

### 2.3 Charts & Visual Reporting
Charts convert tabular figures into immediate visual insights:
- **Column / Bar Charts:** Compare discrete categories side by side.
- **Line Charts:** Highlight continuous trends and growth over time.
- **Pie / Doughnut Charts:** Display percentage shares of a whole.
- Proper formatting—including descriptive chart titles, axis labels, legends, and data labels—ensures reports are self-explanatory.

### 2.4 Pivot Tables & Pivot Charts
A **Pivot Table** (**Insert → PivotTable**) is an interactive cross-tabulation tool that summarizes large datasets without manual formulas:
- Fields are dragged into four areas: **Rows**, **Columns**, **Values** (`Sum`, `Count`, `Average`), and **Filters** (or visual **Slicers**).
- Pairing a Pivot Table with a **Pivot Chart** creates a dynamic report that updates simultaneously whenever filters or slicers are toggled.

---

## 3. Steps for Implementation
1. Open Microsoft Excel, create a new workbook named `data_analysis_report.xlsx`, and organize raw tabular data on Sheet 1 (`Raw_Data`) with clear column headers and zero blank rows.
2. Convert the data range into a structured Excel Table (`Ctrl + T`) and add calculated columns using core functions (`SUM`, `AVERAGE`, `IF`, `COUNTIF`, `SUMIF`, and `VLOOKUP`) with appropriate relative and absolute (`$`) cell references.
3. Apply **Multi-Level Sorting** (under **Data → Sort**) to organize records hierarchically, and use **AutoFilter** to isolate specific subsets for verification.
4. Highlight key summary ranges and insert **Column**, **Pie**, and **Line** charts (**Insert → Charts**), adding chart titles, axis labels, and data labels.
5. Select the dataset and click **Insert → PivotTable** to generate an interactive summary report on a new worksheet (`Pivot_Analysis`), dragging category fields into **Rows/Columns** and numerical metrics into **Values**, accompanied by a **Pivot Chart** and **Slicer**.
6. Save the workbook as `data_analysis_report.xlsx`, export a PDF copy (`data_analysis_report.pdf`), and capture a screenshot (`output.png`) for GitHub documentation.

---

## 4. Files in This Folder
- [`data_analysis_report.xlsx`](./data_analysis_report.xlsx) — Complete Excel workbook containing raw data, formulas, charts, and Pivot Tables.
- [`data_analysis_report.pdf`](./data_analysis_report.pdf) — PDF export for direct in-browser viewing on GitHub *(recommended)*.
- [`output.png`](./output.png) — Screenshot preview of the charts and Pivot Table report *(upload your screenshot with this filename)*.

---

## 5. Summary of Excel Functions & Analytical Tools Used

| Feature / Function | Syntax / Tool Path | Purpose in Analysis |
| :--- | :--- | :--- |
| **Aggregation** | `=SUM(range)`, `=AVERAGE(range)` | Calculates totals and mean performance across records |
| **Conditional Logic** | `=IF(condition, true_val, false_val)` | Classifies records (e.g., Pass/Fail, Target Met/Pending) |
| **Conditional Summary** | `=SUMIF(range, criteria, sum_range)`, `=COUNTIF(...)` | Computes category-wise totals and frequency counts |
| **Data Lookup** | `=VLOOKUP(lookup_val, table_array, col_idx, FALSE)` | Fetches matching attributes from reference tables |
| **Sorting & Filtering** | **Data → Sort** & **Data → Filter** (`Ctrl + T`) | Orders multi-level records and isolates specific subsets |
| **Charts & Pivot Tables** | **Insert → Charts** & **Insert → PivotTable** | Visualizes trends/shares and cross-tabulates large datasets |

---

## 6. Report Output Preview
![Practical 06 Excel Data Analysis Preview](./output.png)

---

## 7. Observation
- Using absolute cell references (`$`) prevented formula reference shifts when dragging calculations across hundreds of rows.
- Multi-level sorting and AutoFilters isolated specific categories and top-performing entries instantly without altering the underlying dataset.
- Pivot Tables aggregated multi-column records dynamically in seconds, and linked Pivot Charts updated automatically whenever filter criteria changed.

---

## 8. Conclusion
In this practical, data analysis and visual reporting were successfully performed in Microsoft Excel using formulas, built-in functions, sorting, filtering, charts, and Pivot Tables. Combining structured formulas with interactive Pivot Tables transforms raw spreadsheets into clear, decision-ready analytical reports.
