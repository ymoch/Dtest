# -*- coding:utf-8 -*-

"""
Create multi-value-matcher header
"""

__author__  = "ymoch"
__date__    = "2014-10-21"

import string
import datetime
import os.path

DEPTH = 10
TARGET_PATH = "../../include/dtest/dtest-matcher-multi-generated.h"
HEADER_TEMPLATE_PATH = "./dtest-matcher-multi-generated.h.tpl"
CLASS_TEMPLATE_PATH  = "./dtest-matcher-multi-class.tpl"

## create tuple
def create_tuple(depth, template_string):
	type_array = []
	for i in range(2, depth + 1):
		template = string.Template(template_string)
		type_array.append(template.safe_substitute(n = i))
	return ", ".join(type_array)

## create class definition
def create_class_definition(depth):
	class_def_string = ""

	for i in range(2, depth + 1):
		class_template = string.Template(open(CLASS_TEMPLATE_PATH).read())

		def_tail      = create_tuple(i, "class T$n")
		def_tail_args = create_tuple(i, "const T$n& v$n")
		tail          = create_tuple(i, "T$n")
		tail_args     = create_tuple(i, "v$n")
		class_def_string += class_template.safe_substitute(
				n = i,
				prev_n = i - 1,
				def_tail = def_tail,
				def_tail_args = def_tail_args,
				tail = tail,
				tail_args = tail_args)

	return class_def_string

## main
if __name__ == "__main__":
	header_template = string.Template(open(HEADER_TEMPLATE_PATH).read())
	class_def_string = create_class_definition(DEPTH)
	date = datetime.datetime.today()

	with open(TARGET_PATH, "w") as out:
		print >> out, header_template.safe_substitute(
				author = os.path.basename(__file__),
				date = "%04d-%02d-%02d" % (date.year, date.month, date.day),
				class_definitions = class_def_string),

