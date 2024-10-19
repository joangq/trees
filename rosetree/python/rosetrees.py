def traverse_nodes(node, sb, padding, pointer, has_right_sibling, show):
    sb.append("\n" + padding + pointer + str(show(node)))

    padding_builder = padding + ("│  " if has_right_sibling else "   ")
    padding_for_both = padding_builder

    if 'children' in node:
        children = node['children'][::-1]
        for child in children[:-1]:
            traverse_nodes(child, sb, padding_for_both, "├──", True, show=show)
        else:
            traverse_nodes(children[-1], sb, padding_for_both, "└──", False, show=show)


def traverse_pre_order(tree, show=lambda x: x['id']):
    result_sb = [str(show(tree))]

    if 'children' in tree:
        children = tree['children'][::-1]
        for child in children[:-1]:
            traverse_nodes(child, result_sb, "", "├──", True, show=show)
        else:
            traverse_nodes(children[-1], result_sb, "", "└──", False, show=show)

    return "".join(result_sb)

tree = {
    'id': 'root',
    'children': [
        {'id': 'child1', 'children': [
            {'id': 'grandchild1'},
            {'id': 'grandchild2'},
            {'id': 'grandchild3'}
        ]},
        {'id': 'child2'},
        {'id': 'child3'}
    ]
}

print(traverse_pre_order(tree))
