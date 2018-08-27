target("ldev")
	set_kind("static")
	add_files("src/*.c")

target("test")
	set_kind("binary")
	add_files("test/*.c")
	add_deps("ldev")
	
