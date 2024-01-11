import unittest
from src.DigitalDict import DigitalDict


class DigitalDictTests(unittest.TestCase):
    def setUp(self):
        self.without_prefixes = DigitalDict()
        self.with_prefixes = DigitalDict()

        self.without_prefixes.insert(("hola", 1))
        self.without_prefixes.insert(("chau", 2))
        self.without_prefixes.insert(("adios", 3))

        self.with_prefixes.insert(("c", 1))
        self.with_prefixes.insert(("casa", 2))
        self.with_prefixes.insert(("casona", 3))

    def test_empty(self):
        vacio = DigitalDict()

        self.assertTrue(vacio.empty())
        self.assertEqual(vacio.count("hola"), 0)

    def test_assign(self):
        singleton = DigitalDict()
        singleton.insert(("hola", 1))

        self.assertEqual(singleton.at("hola"), 1)
        self.assertEqual(singleton.size(), 1)

    def test_get(self):
        self.assertEqual(self.without_prefixes.at("hola"), 1)
        self.assertEqual(self.without_prefixes.at("chau"), 2)
        self.assertEqual(self.without_prefixes.at("adios"), 3)

        self.assertEqual(self.with_prefixes.at("c"), 1)
        self.assertEqual(self.with_prefixes.at("casa"), 2)
        self.assertEqual(self.with_prefixes.at("casona"), 3)

    def test_redefinition(self):
        con_prefijos = DigitalDict()

        con_prefijos.insert(("c", 1))
        con_prefijos.insert(("casa", 2))
        con_prefijos.insert(("casona", 3))

        con_prefijos.insert(("c", 2))
        self.assertEqual(con_prefijos.at("c"), 2)

        con_prefijos.insert(("c", 3))
        self.assertEqual(con_prefijos.at("c"), 3)

    def test_count(self):
        vacio = DigitalDict()

        self.assertFalse(vacio.count("a") == 1)
        self.assertFalse(vacio.count("aaaa") == 1)
        self.assertFalse(vacio.count("adios") == 1)

        self.assertTrue(self.without_prefixes.count("hola") == 1)
        self.assertTrue(self.without_prefixes.count("chau") == 1)
        self.assertTrue(self.without_prefixes.count("adios") == 1)

        self.assertFalse(self.without_prefixes.count("h") == 1)
        self.assertFalse(self.without_prefixes.count("ho") == 1)
        self.assertFalse(self.without_prefixes.count("hol") == 1)

        self.assertTrue(self.with_prefixes.count("c") == 1)
        self.assertTrue(self.with_prefixes.count("casa") == 1)
        self.assertTrue(self.with_prefixes.count("casona") == 1)
        self.assertFalse(self.with_prefixes.count("ca") == 1)
        self.assertFalse(self.with_prefixes.count("cas") == 1)
        self.assertFalse(self.with_prefixes.count("caso") == 1)

    def test_copy(self):
        copy_w = DigitalDict.from_other(self.without_prefixes)

        self.assertTrue(copy_w.count("hola") == 1)
        self.assertTrue(copy_w.count("chau") == 1)
        self.assertTrue(copy_w.count("adios") == 1)

        self.assertFalse(copy_w.count("h") == 1)
        self.assertFalse(copy_w.count("ho") == 1)
        self.assertFalse(copy_w.count("hol") == 1)

        self.assertEqual(self.without_prefixes.at("hola"), copy_w.at("hola"))
        self.assertEqual(self.without_prefixes.at("chau"), copy_w.at("chau"))
        self.assertEqual(self.without_prefixes.at("adios"), copy_w.at("adios"))

        copy_wo = DigitalDict.from_other(self.with_prefixes)

        self.assertTrue(copy_wo.count("c") == 1)
        self.assertTrue(copy_wo.count("casa") == 1)
        self.assertTrue(copy_wo.count("casona") == 1)
        self.assertFalse(copy_wo.count("ca") == 1)
        self.assertFalse(copy_wo.count("cas") == 1)
        self.assertFalse(copy_wo.count("caso") == 1)

        self.assertEqual(copy_wo.at("c"), 1)
        self.assertEqual(copy_wo.at("casa"), 2)
        self.assertEqual(copy_wo.at("casona"), 3)

    def test_no_aliasing(self):
        singleton = DigitalDict()
        singleton.insert(("hola", 1))

        copy = DigitalDict.from_other(singleton)
        copy.insert(("hare", 2))
        self.assertFalse(singleton.count("hare") == 1)

    def test_TrieOfTries(self):
        empty = DigitalDict()
        singleton = DigitalDict()
        dicc_dicc = DigitalDict()

        singleton.insert(("hola", 1))

        dicc_dicc.insert(("empty", empty))
        dicc_dicc.insert(("singleton", singleton))
        dicc_dicc.insert(("without_prefixes", self.without_prefixes))
        dicc_dicc.insert(("with_prefixes", self.with_prefixes))

        self.assertFalse(dicc_dicc.at("empty").count("hola") == 1)
        self.assertEqual(dicc_dicc.at("singleton").at("hola"), 1)
        self.assertEqual(dicc_dicc.at("without_prefixes").at("hola"), 1)
        self.assertEqual(dicc_dicc.at("without_prefixes").at("chau"), 2)
        self.assertEqual(dicc_dicc.at("without_prefixes").at("adios"), 3)
        self.assertEqual(dicc_dicc.at("with_prefixes").at("c"), 1)
        self.assertEqual(dicc_dicc.at("with_prefixes").at("casa"), 2)
        self.assertEqual(dicc_dicc.at("with_prefixes").at("casona"), 3)

    def test_eraseUnicaClave(self):
        singleton = DigitalDict()
        singleton.insert(("hola", 1))

        self.assertTrue(singleton.count("hola") == 1)

        singleton.erase("hola")

        self.assertFalse(singleton.count("hola") == 1)

    def test_erase(self):
        self.with_prefixes.erase("c")
        self.assertFalse(self.with_prefixes.count("c") == 1)

        self.assertTrue(self.with_prefixes.count("casa") == 1)
        self.assertTrue(self.with_prefixes.count("casona") == 1)

        self.with_prefixes.erase("casona")
        self.assertFalse(self.with_prefixes.count("casona") == 1)

        self.assertTrue(self.with_prefixes.count("casa") == 1)

        self.with_prefixes.erase("casa")
        self.assertFalse(self.with_prefixes.count("casa") == 1)

        self.without_prefixes.erase("hola")
        self.assertFalse(self.without_prefixes.count("hola") == 1)

        self.without_prefixes.erase("chau")
        self.assertFalse(self.without_prefixes.count("chau") == 1)

        self.without_prefixes.erase("adios")
        self.assertFalse(self.without_prefixes.count("adios") == 1)

    def test_operator_corchetes(self):
        with_prefixes = DigitalDict()
        without_prefixes = DigitalDict()

        with_prefixes["hola"] = 1
        with_prefixes["chau"] = 2
        with_prefixes["adios"] = 3

        without_prefixes["c"] = 1
        without_prefixes["casa"] = 2
        without_prefixes["casona"] = 3

        self.assertEqual(with_prefixes["hola"], 1)
        self.assertEqual(with_prefixes["chau"], 2)
        self.assertEqual(with_prefixes["adios"], 3)

        self.assertEqual(without_prefixes["c"], 1)
        self.assertEqual(without_prefixes["casa"], 2)
        self.assertEqual(without_prefixes["casona"], 3)
