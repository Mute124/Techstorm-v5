import os

if __name__ == "__main__":
    # If windows, then call build-windows.bat. Otherwise, call build-linux.sh
    if (os.name == "nt"):
        os.system("build-windows.bat")
    else:
        os.system("build-linux.sh")