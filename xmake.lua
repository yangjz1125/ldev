target("ldev")
	set_kind("static")
	add_headers("(ldev/*.h)")
	add_files("ldev/*.c")

target("ldev_test")
	set_kind("binary")
	add_files("test/*.c")
	add_deps("ldev")
	
