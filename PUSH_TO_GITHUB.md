# Push this lab to GitHub

This archive is already a local Git repository with an initial commit.

The GitHub connector available in this ChatGPT session can edit repositories that already exist, but it does **not** expose a create-repository operation. Create one empty repository in GitHub (for example `elite-swe-interview-lab`). Then either tell ChatGPT the new repository name and ask it to work in it, or run:

```bash
git remote add origin git@github.com:<your-user>/elite-swe-interview-lab.git
git push -u origin main
```

If you intentionally remove `.git` before using it, initialize it first with `git init && git add . && git commit -m "Initial interview lab"`.
