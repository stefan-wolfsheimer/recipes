def test_lexical_scope():
    variable = 1
    func = lambda: variable
    assert(func() == 1)
    variable = 2
    assert(func() == 2)


def test_dynamic_scope_1():
    variable = 1
    func = lambda variable=variable: variable
    assert(func() == 1)
    variable = 2
    assert(func() == 1)


def test_dynamic_scope_2():
    variable = 1
    func = (lambda variable: lambda: variable)(variable)
    assert(func() == 1)
    variable = 2
    assert(func() == 1)

if __name__ == '__main__':
    test_lexical_scope()
    test_dynamic_scope_1()
    test_dynamic_scope_2()
