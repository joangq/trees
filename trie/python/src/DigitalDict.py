from typing import List, Tuple, TypeVar
import copy

T = TypeVar('T')


def all_none(xs):
    return all(map(lambda x: x is None, xs))


class TrieNode:
    next: 'List[None|TrieNode]'
    value: 'None | T'

    def __init__(self):
        self.next = [None for _ in range(256)]
        self.value = None

    @staticmethod
    def destruir_nodos(r: 'TrieNode'):
        if r is None:
            return

        if r.next is not None:
            r.value = None

        if len(r.next) != 0:
            for item in r.next:
                TrieNode.destruir_nodos(item)


class DigitalDict:
    root: TrieNode
    _size: int
    _keys: set[str]

    def __init__(self):
        self.root = TrieNode()
        self._size = 0
        self._keys = set()

    @staticmethod
    def from_other(copy_from: 'DigitalDict'):
        return copy.deepcopy(copy_from)

    @staticmethod
    def __define__(key: str, value: T, r: TrieNode):
        for i in map(ord, key):
            if r.next[i] is None:
                r.next[i] = TrieNode()

            r = r.next[i]

        if r.value is not None:
            r.value = None

        r.value = value

    def insert(self, key_value_pair: Tuple[str, T]):
        """Inserts a key-value pair into the dictionary."""
        key, value = key_value_pair

        if self.count(key) == 0:
            self._size += 1
            self._keys.add(key)

        if self.root is None:
            self.root = TrieNode()

        DigitalDict.__define__(key, value, self.root)

    def count(self, key: str) -> int:
        """Returns the number of occurrences of the key (0 or 1). Identifies whether a key is defined or not."""
        if self.root is None:
            return 0

        r = self.root
        for i in map(ord, key):
            if r.next[i] is None:
                return 0
            r = r.next[i]

        return 1 if r.value is not None else 0

    def at(self, key: str) -> T:
        """
        Given a key, returns its value.
        Precondition : The key is defined.
        """
        r = self.root
        for i in map(ord, key):
            r = r.next[i]

        return r.value

    @staticmethod
    def recorrer(r: TrieNode, recorrido: list[int]) -> TrieNode:
        n: TrieNode = r
        for x in recorrido:
            n = n.next[x]
        return n

    def erase(self, key: str):
        """
        Given a key, deletes it from the dictionary along with its value.
        Precondition: The key is defined.
        PRODUCES ALIASING
        """
        self._size -= 1
        self._keys.remove(key)

        ordkey: List[int] = list(map(ord, key))
        mapa: List[int] = [0 for _ in range(len(key))]
        nodos: List[None | TrieNode] = [None for _ in range(len(key))]

        i = 0
        while len(ordkey) > 0:
            nodos[i] = DigitalDict.recorrer(self.root, ordkey)
            mapa[i] = mapa[-1]
            ordkey.pop()
            i += 1

        if not all_none(nodos[0].next):
            if nodos[0].value is not None:
                nodos[0].value = None
            return

        TrieNode.destruir_nodos(nodos[0])
        nodos[1].next[mapa[0]] = None
        nodos = nodos[1:]
        mapa = mapa[1:]

        while len(nodos) > 1:
            if nodos[0].value is not None or not all_none(nodos[0].next):
                break

            # TrieNode.destruir_nodos(nodos[0])
            # nodos[1].next[mapa[0]] = None
            # nodos = nodos[1:]
            # mapa = mapa[1:]

        if (len(nodos) < 1) or (nodos[0].value is not None) or (not all_none(nodos[0].next)):
            return

        # TrieNode.destruir_nodos(nodos[0])
        # self.root.next[mapa[0]] = None
        # nodos = nodos[1:]
        # mapa = mapa[1:]

    def size(self) -> int:
        """Returns the number of defined keys"""
        return self._size

    def empty(self) -> bool:
        """Returns true if there are no elements in the dictionary"""
        return self._size == 0

    def __getitem__(self, key: str) -> T:
        return self.at(key)

    def __setitem__(self, key: str, value: T) -> T:
        return self.insert((key, value))

    def keys(self) -> list[str]:
        return list(self._keys)
