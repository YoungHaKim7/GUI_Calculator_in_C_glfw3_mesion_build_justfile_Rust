# 파이썬 현재 폴더명만 반환
```
print(f"[1] '{os.path.basename(os.getcwd())}'")
```

- 여기까지 근접
```meson
 # Extract the folder name from the source root path
# project_folder_name = run_command('python3', -c 'import os; print(f"[1] {os.path.basename(os.getcwd())}")')

# Extract the folder name from the current working directory
project_folder_name = run_command('python3', '-c', 'import os; print(f"[1] {os.path.basename(os.getcwd())}")', check: true).stdout().strip()
```
