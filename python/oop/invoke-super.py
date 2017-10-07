###############################################################################
# Call parent constructors and methods
#
# Animal is a new-style class (inheritated from object)
#


class Animal(object):
    def __init__(self, name):
        self.name = name

    def get_name(self):
        return self.name

    def title(self):
        return self.name


class Dog(Animal):
    def __init__(self, name):
        super(Dog, self).__init__(name)

    def title(self):
        return super(Dog, self).title() + ', the dog'


if __name__ == '__main__':
    dog = Dog('Nico')
    print dog.get_name()
    print dog.title()
