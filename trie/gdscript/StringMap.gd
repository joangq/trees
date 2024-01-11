class_name StringMap extends Reference

const ASCII_CHARACTERS = [null, null, null, null, null, null, 
						  null, null, null, '\t', '\n', null, null, 
						  '\r', null, null, null, null, null, null, 
						  null, null, null, null, null, null, null, 
						  null, null, null, null, null, ' ', '!', '"', 
						  '#', '$', '%', '&', "'", '(', ')', '*', '+', ',', '-', 
						  '.', '/', '0', '1', '2', '3', '4', '5', '6', '7', '8', 
						  '9', ':', ';', '<', '=', '>', '?', '@', 'A', 'B', 'C', 
						  'D', 'E', 'F', 'G', 'H', 'I', 'J', 'K', 'L', 'M', 'N', 
						  'O', 'P', 'Q', 'R', 'S', 'T', 'U', 'V', 'W', 'X', 'Y', 
						  'Z', '[', '\\', ']', '^', '_', '`', 'a', 'b', 'c', 'd', 
						  'e', 'f', 'g', 'h', 'i', 'j', 'k', 'l', 'm', 'n', 'o', 
						  'p', 'q', 'r', 's', 't', 'u', 'v', 'w', 'x', 'y', 'z', 
						  '{', '|', '}', '~', null]

const Functions = preload("res://Functions.gd")

# TrieNode =================================================================== #

class TrieNode:
	var next # List[null|TrieNode]
	var value # null | T
	
	func _init():
		self.next = []
		self.next.resize(256)
		for i in 256:
			self.next[i] = null
		
		self.value = null
	
	static func destruir_nodos(r):
		if r == null:
			return
		
		if r.next == null:
			r.value = null
		
		if r.next.size() != 0:
			for item in r.next:
				TrieNode.destruir_nodos(item)
		
		return

# DigitalDict ================================================================ #

class DigitalDict:
	var root
	var _size
	var _keys
	
	func _init():
		self.root = TrieNode.new()
		self._size = 0
		self._keys = []
	
	static func _define(key, value, r): # (str, T, TrieNode)
		for i in Functions.str_to_ord(key):
			if r.next[i] == null:
				r.next[i] = TrieNode.new()
			
			r = r.next[i]
		
		if r.value != null:
			r.value = null
		
		r.value = value

	func count(key: String) -> int:
		if self.root == null:
			return 0
		
		var r = self.root
		for i in Functions.str_to_ord(key):
			if r.next[i] == null:
				return 0
			r = r.next[i]
		
		return 1 if r.value != null else 0
	
	func insert(key_value_pair: Array):
		var key = key_value_pair[0]
		var value = key_value_pair[1]
		
		if self.count(key) == 0:
			self._size += 1
			self._keys.append(key)
		
		if self.root == null:
			self.root = TrieNode.new()
		
		DigitalDict._define(key, value, self.root)
	
	func at(key: String): # -> T
		var r = self.root
		for i in Functions.str_to_ord(key):
			r = r.next[i]
		
		return r.value

	static func recorrer(r: TrieNode, recorrido: Array) -> TrieNode:
		var n : TrieNode = r
		for x in recorrido:
			n = n.next[x]
		return n
	
	func erase(key: String):
		self._size -= 1
		self._keys.erase(key)
		
		var ordkey = Functions.str_to_ord(key) # Array[int ^ ord]
		var mapa = [] # Array[int]
		var nodos = [] # Array[null | TrieNode]
		mapa.resize(key.length())
		nodos.resize(key.length())
		for i in mapa.size():
			mapa[i] = 0
			nodos[i] = null
		
		var i = 0
		while not ordkey.empty():
			nodos[i] = DigitalDict.recorrer(self.root, ordkey)
			mapa[i] = mapa[mapa.size()-1]
			ordkey.pop()
			i += 1
			
		if not Functions.all_none(nodos[0].next):
			if nodos[0].value != null:
				nodos[0].value = null
			return
		
		TrieNode.destruir_nodos(nodos[0])
		nodos[1].next[mapa[0]] = null
		nodos.remove(0)
		mapa.remove(0)
		
		while nodos.size() > 1:
			if (nodos[0].value != null) or (Functions.all_none(nodos[0].next)):
				break
				
			TrieNode.destruir_nodos(nodos[0])
			nodos[1].next[mapa[0]] = null
			nodos.remove(0)
			mapa.remove(0)
		
		if (nodos.size() < 1) \
			or (nodos[0].value != null) \
			or (not Functions.all_none(nodos[0].next)):
			return
		
		TrieNode.destruir_nodos(nodos[0])
		self.root.next[mapa[0]] = null
		nodos.remove(0)
		mapa.remove(0)
	
	func size():
		return self._size
	
	func empty():
		return self._size == 0
	
	func keys():
		return self._keys

# AutocompleteDict =========================================================== #

class AutocompleteDict extends DigitalDict:
	func _get_suggestions(node, prefix, current_suggestions): # (TrieNode, str, Array)
		if node.value != null:
			current_suggestions.append(prefix)
		
		for i in range(node.next.size()):
			var child_node = node.next[i]
			if child_node != null:
				self._get_suggestions(child_node, prefix + String(ASCII_CHARACTERS[i]), current_suggestions)
		
		return
		
	
	func autocomplete(key: String) -> Array: # Array[String]
		var suggestions = []
		var node = self.root
		
		for ch in key:
			var index = ord(ch)
			if node.next[index] == null:
				return suggestions
			node = node.next[index]
		
		self._get_suggestions(node, key, suggestions)
		return suggestions

# AutocompleteSet ============================================================ #

class AutocompleteSet:
	var dct: AutocompleteDict
	
	func _init():
		self.dct = AutocompleteDict.new()
	
	func add(item: String):
		self.dct.insert([item, 1])
	
	func exists(item: String) -> bool:
		return self.dct.count(item) == 1
	
	func keys():
		return self.dct.keys()
	
	func remove(item: String):
		self.dct.erase(item)
	
	func autocomplete(key: String) -> Array:
		return self.dct.autocomplete(key)
