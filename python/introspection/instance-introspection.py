class MyClass(object):
    pass


def print_info(obj):
    print "type: " + type(obj).__name__

if __name__ == '__main__':
    obj = MyClass()
    print_info(obj)
