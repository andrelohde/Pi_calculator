def compare_files(f1, f2):
	with open(f1, "r") as file1:
		f1_content = file1.read();
	
	with open(f2, "r") as file2:
		f2_content = file2.read();
	
	return f1_content == f2_content
	
if __name__ == "__main__":
	python = compare_files("pi.txt", "pi_py.txt")
	cpp = compare_files("pi.txt", "pi_cpp.txt")
	print(f"1 Million digits of Pi via Python: {python}")
	print(f"1 Million digits of Pi via C++: {cpp}")