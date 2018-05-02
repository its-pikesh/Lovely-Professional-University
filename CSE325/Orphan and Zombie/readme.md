## How to check for zombie process or orphan process?

Open terminal and enter the following command:
```bash
ps -e -o pid,ppid,stat,cmd
```
