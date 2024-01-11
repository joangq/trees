class_name Functions extends Reference

# Simulates Python's slice notation
static func slice(array: Array, start = null, end = null, step: int = 1) -> Array:
	if start == null:
		start = 0
		
	if end == null:
		end = array.size()
		
	var result = []

	var array_length = array.size()
	if start < 0:
		start = max(0, array_length + start)
	if end < 0:
		end = max(0, array_length + end)

	for i in range(start, min(end, array_length), step):
		result.append(array[i])

	return result

static func all_none(xs):
	for x in xs:
		if x != null:
			return false
	return true

static func str_to_ord(s: String) -> Array:
	var result = []
	for c in s:
		result.append(ord(c))
	return result
