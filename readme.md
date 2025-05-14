A simple recreation of git for my learning / fun

# Why did I build this
If you are passionate about software engineering, it is impossible to not use Git.

Throughout school and personal projects, I have learned how to use Git quite well in a solo and group setting, but I had no idea how Git actually works.

So that's how this project started! One day I was curious at how Git really does simplify version control, so I decided to rebuild a smaller version!

## Some key things I learned
* SHA-1 hash encryption
* Object creation (blob, commit, tree)
* Indexing / Staging files for commit (TRACKED file)
* Filesystem manipulation (Traversal, searching, & managing)
* Deterministic Snapshots (reproducable hashes if done exactly the same)

### commands to implement:

* init
* add
* commit
* log
* checkout


### things to implement:
* commit object file contents to include parent commit
* tree objects
* make working refs & heads

### DONE
* appended write function
* recursively find .jgit directory 
* commit and blob object creation
* commit file rewriting
* head file
* .jgit directory creation
* init & init checking
* object creation adds to tracked
* tracking file (in actual Git this is index)
