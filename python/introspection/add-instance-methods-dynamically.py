class MyClass(object):
    def __init__(self, variables=['a', 'b', 'c', 'd']):
        import types
        self.get_variables = types.MethodType(lambda inst: variables, self)
        for var in variables:
            setattr(self, var, None)
            setattr(self,
                    'get_' + var,
                    types.MethodType(lambda inst, var=var:
                                     getattr(inst, var),
                                     self))
            setattr(self,
                    'set_' + var,
                    types.MethodType(lambda inst, value, var=var:
                                     setattr(inst, var, value),
                                     self))


if __name__ == '__main__':
    obj = MyClass(['1', 'a', 'b'])
    obj.set_1('one')
    obj.set_a('A')
    obj.set_b('B')

    print obj.get_1()
    print obj.get_a()
    print obj.get_b()
