All informations on contributing can be found on the [corresponding wiki page.](https://github.com/iScsc/wiresmash/wiki/Contributing) Read at least the general policies section, and specific sections. 

Quick TLDR:
- **FORMAT CODE BEFORE DOING A PULL REQUEST**, see [corresponding section](#formatting-code).
- To contribute, do fork-branch-PR.
- To report bugs, make sure not to create duplicates and create an issue with as many information as possible. Name it `bug-xxx`.
- For feature requests, make an issue named `request-xxx`

## Formatting code<a name="formatting"></a>

It is advised to format code either as you go, but *atleast once* before doing a PR. PR wil provide a fail if the code is not formatted. **Only format files on which you worked.** We use `clang-format`, version `16+` for formatting, and the file is already in the repo (`.clang-format` in root).

A pre-commit hook is provided in `hooks/format-hook`. It is strongly advised that you move the code inside of it to the `.git/hooks/pre-commit` file. It will warn you when you try to commit unformatted code.

To run `clang-format` on a single file, simply run from the root of the repo the following command:
```bash
clang-format -i path/to/file.extension
```
This will overwrite the file, inplace (`-i`), with its formatted version.

You can also stage your change, and then simply run `git clang-format` to format stuff.