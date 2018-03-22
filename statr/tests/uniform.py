import unittest
import sys
sys.path.insert(0, '..')
import statr

class TestStringMethods(unittest.TestCase):

    def test_runif_zero(self):
        result = statr.runif(0)
        self.assertEqual(result, [])

    def test_runif_num(self):
        statr.set_seed(10)
        result = statr.runif(1)
        self.assertEqual(round(result[0], 3), round(0.5074782,3)) #value from R

    def test_runif_range(self):
        statr.set_seed(10)
        result = statr.runif(1, 10, 11)
        self.assertGreater(result[0], 10)
        self.assertLess(result[0], 11)

if __name__ == '__main__':
    unittest.main()