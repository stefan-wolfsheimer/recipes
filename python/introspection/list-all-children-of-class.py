import sys


class Animal(object):
    pass


class Vehicle(object):
    pass


class Dog(Animal):
    pass


class Cat(Animal):
    pass


class Lion(Cat):
    pass


class Tiger(Cat):
    pass


class Car(Vehicle):
    pass


def print_all_classes_of(klass, module):
    import inspect
    print "----------------------------------------"
    print "All '%s' clases:" % klass.__name__
    print "----------------------------------------"
    issub = lambda k: inspect.isclass(k) and issubclass(k, klass)
    for subklass in inspect.getmembers(module, issub):
        print subklass[0]
    print
    pass

if __name__ == '__main__':
    module = sys.modules[__name__]
    print_all_classes_of(Animal, module)
    print_all_classes_of(Cat, module)
    print_all_classes_of(Vehicle, module)
