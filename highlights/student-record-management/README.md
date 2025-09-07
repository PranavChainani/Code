# Student Record Management System (Highlight)

**Stack:** C  
**Role:** Individual  

## Problem
Manage thousands of student records (ID + Age) efficiently under different real-world usage patterns: search-heavy, deletion-heavy, and dynamic growth. Also support computing the maximum age gap across current records.

## Scenarios (what this project shows)
- **Age-based search & max age gap** — optimized for many lookups, rare updates.
- **ID-based lookup** — optimized for fast direct access.
- **Dynamic growth** — optimized for frequent insertions/deletions.

## Interfaces
`createDataSet`, `destroyDataSet`, `searchAge`, `searchID`, `insertion`, `deletion`, `maxAgeGap`.

## Approach (high level)
- Pick the data structure that fits each scenario (arrays vs hash tables vs linked structures).
- Keep a clean API so the same test driver can run multiple strategies.
- Use randomized test data (≈1,000 records) to validate correctness and compare behavior.

## Results (placeholder)
Add a small table in `docs/metrics.md` with runtime/operations for each scenario.

## How to run (placeholder)
See each scenario folder for a `README.md` and a one-command run script.

## What I’d do next (PM lens)
Add telemetry (timings per operation), a small CLI to switch strategies, and a CSV export for analysis.
