import threading
import time

def load_html():
    print("Loading HTML...")
    time.sleep(2)
    print("HTML Loaded.")

def load_css():
    print("Loading CSS...")
    time.sleep(1)
    print("CSS Loaded.")

def load_images():
    print("Loading Images...")
    time.sleep(3)
    print("Images Loaded.")

def load_javascript():
    print("Executing JavaScript...")
    time.sleep(2)
    print("JavaScript Executed.")

# Without multithreading (Sequential)
start = time.time()
load_html()
load_css()
load_images()
load_javascript()
print("Single-threaded Total Time:", time.time() - start, "seconds\n")

# With multithreading (Parallel)
start = time.time()
threads = []
for task in [load_html, load_css, load_images, load_javascript]:
    thread = threading.Thread(target=task)
    threads.append(thread)
    thread.start()

for thread in threads:
    thread.join()

print("Multi-threaded Total Time:", time.time() - start, "seconds")
