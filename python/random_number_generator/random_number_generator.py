#!/usr/bin/python3
from random import uniform, randint
import unittest

def randNumGenerator(numbType, numMin, numMax, numb):
    """
    numbType: an "int" for initerator, and a "float" for float number.
    numMin: The nimimum for the number generatored.
    numMax: the maximum for the number generatored.
    numb: the number of numbers generatored.
    """
    if numbType == "int":
        generator = randint
    elif numbType == "float":
        generator = uniform
    else:
        raise AttributeError("invalid value for type: %s" % numbType)
    numMin = int(numMin)
    numMax = int(numMax)
    numb   = int(numb)


    while numb > 0:
        yield generator(numMin, numMax);
        numb -= 1

class TestRandNumGenerator(unittest.TestCase):

    def test_generatorInit(self):
       i = 0
       for n in randNumGenerator("int", 0, 10000, 20):
            i += 1
            self.assertTrue(n >= 0)
            self.assertTrue(n <= 10000)
            self.assertTrue(isinstance(n, int))

       self.assertEqual(i, 20)

    def test_generatorFloat(self):
        i = 0
        for n in randNumGenerator("float", 0, 10000, 20):
            i += 1
            self.assertTrue(n >= 0)
            self.assertTrue(n <= 10000)
            self.assertTrue(isinstance(n, float))

        self.assertEqual(i, 20)


    def test_typeError(self):
        with self.assertRaises(AttributeError):
            g = randNumGenerator("unknowType", 0, 10000, 20)
            g.__next__()


def writeToFile():
    path = input("Please input the whole path of file:\n")
    numType = input('You want to generate "int" or "float"?\ntype "int" or "float":\n')
    minNum = input('the minimum value of the generated numbers:')
    maxNum = input('the maximum value of the generated numbers:')
    numb = input('the number you want to generate:')
    separator = input('the separator:')
    import sys
    sys.path.append("..")
    from mypackage.myio import MyIo
    myio = MyIo(path)


    myio.writeSeperated(randNumGenerator(numType, minNum, maxNum, numb))



if __name__ == '__main__':
    writeToFile();
    #unittest.main()

