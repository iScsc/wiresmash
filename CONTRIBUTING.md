All informations on contributing can be found on the [corresponding wiki page.](https://github.com/iScsc/wiresmash/wiki/Contributing) Read at least the general policies section, and specific sections. 

Quick TLDR:
- **FORMAT CODE BEFORE DOING A PULL REQUEST**, see [corresponding section](#formatting-code).
- To contribute, do fork-branch-PR.
- To report bugs, make sure not to create duplicates and create an issue with as many information as possible. Name it `bug-xxx`.
- For feature requests, make an issue named `request-xxx`

## Formatting code<a name="formatting"></a>

It is advised to format code either as you go, but *atleast once* before doing a PR. PR wil provide a fail if the code is not formatted. **Only format files on which you worked.** We use `clang-format`, version `16+` for formatting, and the file is already in the repo (`.clang-format` in root).

A pre-commit hook for formatting is provided in `.githooks/pre-commit`. It is strongly advised that you setup the hook by running `git config --local core.hooksPath .githooks`.It will warn you when you try to commit unformatted code, and prevent you from pushing it.

### Running clang-format

#### **On staged files**
You can run `git clang-format` to format staged files.

#### **On a single file**
To run `clang-format` on a single file, run the following command:
```bash
clang-format -i path/to/file.extension
```

This will overwrite the file, replacing it with its formatted version.
