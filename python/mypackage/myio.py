#!/usr/bin/python3

"""
Some customization io operation.
"""

class MyIo(object):
    def __init__(self, path):
        self.path = path

    def writeSeperated(self, generator, separator = " "):
        """
        generator: a generator to generate fragments to write in file
        separator: separator between fragments.
        """
        
        with open(self.path, "w") as f:
            for frag in generator:
                f.write(str(frag))
                f.write(str(separator))

        f.close()


if __name__ == '__main__':
    myio = MyIo("/tmp/MyIotest")

    g = range(10)
    myio.writeSeperated(g, ", ")

