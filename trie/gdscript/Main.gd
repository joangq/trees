class_name Main extends Node2D

const StringMap = preload("res://StringMap.gd")
const AutocompleteSet = StringMap.AutocompleteSet

func _ready():
	var d = AutocompleteSet.new()
	d.add('casa')
	d.add('casona')
	d.add('casar')
	d.add('cesar')
	print(d.autocomplete(''))
