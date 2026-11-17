# Skills migration report — devices-raspberry-pi-xpack

The rules of the original skills (kept as `*-original.*` files until they are deleted) that are not word-for-word in the new generated skills and project files; the rows that are the same are left out. Score: fraction of the words of the rule found in the best-matching text of the new files. Verdicts of the unmatched rows were set after reading them, per skill, not per row.

## code-review

| Backup section | Rule (start) | Where it is now | Score | Verdict |
| --- | --- | --- | --- | --- |
| Review Scope | If the user specifies a path, review only that path. Otherwise review | code-review/SKILL.md (Review Scope) | 0.78 | same, plus commit-range scope added |
| Naming and style | - Formatting matches `.clang-format` (run `xpm run clang-format` menta | code-review/SKILL.md (Tooling Verification) | 0.44 | CHANGED: replaced by a real clang-format --dry-run check (Tooling Verification) |
| Correctness and maintainability | - Look for undefined behaviour, missing `const`-correctness, and incor | code-review/SKILL.md (Correctness) | 0.74 | split: generic inline-assembly rule; AArch64 detail dropped for µTest++ (goes to architecture-aarch64 project.md) |
| Correctness and maintainability | - Check for potential ABI implications of changes to the public types | code-review/SKILL.md (Correctness) | 0.83 | reworded: 'interfaces shared with other components'; semihosting detail to architecture-aarch64 |
| Correctness and maintainability | - Check API symmetry between the parallel forms of each API (the `aarc | code-review/SKILL.md (Correctness) | 0.73 | split: generic symmetry rule; AArch64 names to architecture-aarch64 project.md |
| Correctness and maintainability | - Check API symmetry between related class templates (e.g. `doubly_lis | code-review/SKILL.md (Correctness) | 0.37 | merged into the generic symmetry rule; list names to utils-lists project.md |
| Toolchain verification | - Where feasible, prefer verifying claims by actually building rather | code-review/SKILL.md (Tooling Verification) | 0.77 | reworded: run the tests of project.md (Tests) |
| Toolchain verification | - For pointer-arithmetic or type-punning idioms (e.g. `reinterpret_cas | code-review/SKILL.md (Tooling Verification) | 0.84 | reworded: build a sanitizer probe |
| Tests | - Note if `xpm run test -C tests` (and the clang/qemu variants mention | code-review/SKILL.md (Tests) | 0.55 | reworded: refers to project.md (Tests) |
| Procedure | 5. Write the results to `CODE-REVIEW.md` at the root of the project, w | code-review/SKILL.md (Report) | 0.57 | CHANGED: report is maintenance/docs/CODE-REVIEW-<n>.md (review-common Report Files) |
| Procedure | - a summary of findings, and | code-review/SKILL.md (Report) | 0.83 | same (Report template, Summary line) |
| Procedure | - specific, actionable recommendations, grouped by checklist section. | code-review/SKILL.md (Report) | 0.63 | same (Report template, sections per checklist) |
| Procedure | 6. Index open issues numerically, to be refered when asking to close t | review-common.md (Numbering) | 0.38 | moved: review-common.md (Numbering) |

## consistency-check

| Backup section | Rule (start) | Where it is now | Score | Verdict |
| --- | --- | --- | --- | --- |
| Scope | If the user specifies a folder, check only that folder. Otherwise chec | consistency-check/SKILL.md (When to Use) | 0.85 | reworded: report numbered, tests rule conditional on a tests folder |
| 1. Functional consistency | - **Build and test configurations** (e.g. `tests/package.json`): the a | consistency-check/SKILL.md (frontmatter) | 0.39 | reworded: report numbered, tests rule conditional on a tests folder |
| 3. Names | - Similar items placed inconsistently (e.g. a platform-level file kept | consistency-check/SKILL.md (3. Names) | 0.79 | reworded: example generalised ('a file kept in one sibling folder only') |
| Numbering | - The numbers never change once assigned. When the report already exis | consistency-check/SKILL.md (Numbering), review-common.md (Numbering) | 0.52 | same (reworded into consistency-check Numbering + review-common) |
| Numbering | - If a problem turns out to be wrong, mark it `(withdrawn)`, with the | review-common.md (Numbering) | 0.74 | moved: review-common.md (Numbering) |
| Numbering | - When the user later refers to a number (e.g. "fix #7"), act on that | consistency-check/SKILL.md (Procedure 6) | 0.75 | moved: Procedure 6 + review-common.md (Acting on an Item) |

## doxygen-review

| Backup section | Rule (start) | Where it is now | Score | Verdict |
| --- | --- | --- | --- | --- |
| Step 2 — Read and Verify Against the Code | - **Shared enumerations and options.** Describe the behaviour of every | - | 0.67 | dropped: a past example, removed with the project.md section (your decision) |
| Step 2 — Read and Verify Against the Code | - **Examples.** Every `@code` example must compile and be correct (e.g | - | 0.70 | dropped: a past example, removed with the project.md section (your decision) |
| Step 4 — Verify | 3. Build and run the tests, at least with the system compiler, with cl | doxygen-review/SKILL.md (Step 4) | 0.84 | reworded: refers to project.md (Tests) |

## rewrite-bash-to-javascript

| Backup section | Rule (start) | Where it is now | Score | Verdict |
| --- | --- | --- | --- | --- |
| frontmatter | description: 'Rewrite a bash/shell script (.sh) in this project as an | rewrite-bash-to-javascript/SKILL.md (frontmatter) | 0.84 | reworded: description refers to create-javascript-mjs instead of the two scripts |
| When to Use | - The user wants a new `.mjs` equivalent of an existing shell script, | rewrite-bash-to-javascript/SKILL.md (frontmatter) | 0.37 | covered: Step 2 of the skill, or the conventions of create-javascript-mjs |
| Step 1 — Conversion Conventions | Follow the style already established by [jsonc-format.mjs](../../../ma | rewrite-bash-to-javascript/SKILL.md (When to Use) | 0.21 | covered: Step 2 of the skill, or the conventions of create-javascript-mjs |
| Step 1 — Conversion Conventions | - **Module system**: use ES module syntax (`import`/`export`) with a ` | project-defaults.md (Probes) | 0.30 | covered: Step 2 of the skill, or the conventions of create-javascript-mjs |
| Step 1 — Conversion Conventions | - **Header comment**: keep a `/* ... */` block comment with the same c | rewrite-bash-to-javascript/SKILL.md (Step 1 — General Conventions) | 0.45 | covered: Step 2 of the skill, or the conventions of create-javascript-mjs |
| Step 1 — Conversion Conventions | - **Template processing**: if the script renders Liquid templates, use | rewrite-bash-to-javascript/SKILL.md (Step 2 — Bash-Specific Replacements) | 0.33 | covered: Step 2 of the skill, or the conventions of create-javascript-mjs |
| Step 1 — Conversion Conventions | - **File discovery**: replace `find` invocations with the `glob` packa | rewrite-bash-to-javascript/SKILL.md (Step 2 — Bash-Specific Replacements) | 0.41 | covered: Step 2 of the skill, or the conventions of create-javascript-mjs |
| Step 1 — Conversion Conventions | - **Permission preservation**: if the script edits files that may be r | review-common.md (Report Files) | 0.35 | covered: Step 2 of the skill, or the conventions of create-javascript-mjs |
| Step 1 — Conversion Conventions | - **Output**: use `console.log`/`console.error` instead of `echo`. | rewrite-bash-to-javascript/SKILL.md (Step 2 — Bash-Specific Replacements) | 0.73 | covered: Step 2 of the skill, or the conventions of create-javascript-mjs |
| Step 1 — Conversion Conventions | - **Functions**: use arrow functions rather than the `function` keywor | rewrite-bash-to-javascript/SKILL.md (When to Use) | 0.30 | covered: Step 2 of the skill, or the conventions of create-javascript-mjs |
| Step 1 — Conversion Conventions | - **Synchronous APIs**: prefer synchronous calls (e.g. `readFileSync`, | rewrite-bash-to-javascript/SKILL.md (Step 2 — Bash-Specific Replacements) | 0.25 | covered: Step 2 of the skill, or the conventions of create-javascript-mjs |
| Step 1 — Conversion Conventions | - **Running external tools**: replace the bash `run_verbose` helper (w | rewrite-bash-to-javascript/SKILL.md (Step 2 — Bash-Specific Replacements) | 0.68 | covered: Step 2 of the skill, or the conventions of create-javascript-mjs |
| Step 1 — Conversion Conventions | - **Dependencies**: add any new npm package (e.g. `glob`) to `devDepen | rewrite-bash-to-javascript/SKILL.md (Step 2 — Bash-Specific Replacements) | 0.39 | covered: Step 2 of the skill, or the conventions of create-javascript-mjs |
| Step 1 — Conversion Conventions | - **Wiring**: update the corresponding entry under `xpack.actions` in | rewrite-bash-to-javascript/SKILL.md (Step 2 — Bash-Specific Replacements) | 0.85 | covered: Step 2 of the skill, or the conventions of create-javascript-mjs |

