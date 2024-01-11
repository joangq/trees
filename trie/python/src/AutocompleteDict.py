from src.DigitalDict import DigitalDict, TrieNode
from typing import List


class AutocompleteDict(DigitalDict):
    def __get_suggestions__(self, node: 'TrieNode', prefix: str, current_suggestions):
        """
        :param node: Root node for the recursion.
        :param prefix: Current longest prefix
        :param current_suggestions: Current list of suggestions, mutates with each call.
        """
        if node.value is not None:
            current_suggestions.append(prefix)

        for i, child_node in enumerate(node.next):
            if child_node:
                self.__get_suggestions__(child_node, prefix + chr(i), current_suggestions)

        return

    def autocomplete(self, key: str) -> List[str]:
        """
        :param key: Key to look up.
        :return: A list of all valid keys with the key as prefix.
        """
        suggestions = []
        node = self.root

        for char in key:
            index = ord(char)
            if not node.next[index]:
                return suggestions
            node = node.next[index]

        self.__get_suggestions__(node, key, suggestions)
        return suggestions
