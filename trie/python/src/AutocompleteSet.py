from src.AutocompleteDict import AutocompleteDict


class AutocompleteSet:
    dct: AutocompleteDict

    def __init__(self):
        self.dct = AutocompleteDict()

    def add(self, item: str):
        self.dct.insert((item, 1))

    def exists(self, item: str):
        return self.dct.count(item) == 1

    def keys(self):
        return self.dct.keys()

    def remove(self, item: str):
        self.dct.erase(item)

    def autocomplete(self, key: str):
        return self.dct.autocomplete(key)

    def __str__(self):
        return '{' + ', '.join(self.keys()) + '}'

    def __repr__(self):
        return str(self)

    def __contains__(self, item):
        return self.exists(item)

    def __iter__(self):
        return self.keys()
