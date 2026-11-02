# generated from rosidl_generator_py/resource/_idl.py.em
# with input from tita_system_interfaces:srv/PowerSelfTestSrv.idl
# generated code does not contain a copyright notice


# Import statements for member types

import builtins  # noqa: E402, I100

import rosidl_parser.definition  # noqa: E402, I100


class Metaclass_PowerSelfTestSrv_Request(type):
    """Metaclass of message 'PowerSelfTestSrv_Request'."""

    _CREATE_ROS_MESSAGE = None
    _CONVERT_FROM_PY = None
    _CONVERT_TO_PY = None
    _DESTROY_ROS_MESSAGE = None
    _TYPE_SUPPORT = None

    __constants = {
    }

    @classmethod
    def __import_type_support__(cls):
        try:
            from rosidl_generator_py import import_type_support
            module = import_type_support('tita_system_interfaces')
        except ImportError:
            import logging
            import traceback
            logger = logging.getLogger(
                'tita_system_interfaces.srv.PowerSelfTestSrv_Request')
            logger.debug(
                'Failed to import needed modules for type support:\n' +
                traceback.format_exc())
        else:
            cls._CREATE_ROS_MESSAGE = module.create_ros_message_msg__srv__power_self_test_srv__request
            cls._CONVERT_FROM_PY = module.convert_from_py_msg__srv__power_self_test_srv__request
            cls._CONVERT_TO_PY = module.convert_to_py_msg__srv__power_self_test_srv__request
            cls._TYPE_SUPPORT = module.type_support_msg__srv__power_self_test_srv__request
            cls._DESTROY_ROS_MESSAGE = module.destroy_ros_message_msg__srv__power_self_test_srv__request

            from diagnostic_msgs.msg import DiagnosticArray
            if DiagnosticArray.__class__._TYPE_SUPPORT is None:
                DiagnosticArray.__class__.__import_type_support__()

    @classmethod
    def __prepare__(cls, name, bases, **kwargs):
        # list constant names here so that they appear in the help text of
        # the message class under "Data and other attributes defined here:"
        # as well as populate each message instance
        return {
        }


class PowerSelfTestSrv_Request(metaclass=Metaclass_PowerSelfTestSrv_Request):
    """Message class 'PowerSelfTestSrv_Request'."""

    __slots__ = [
        '_power_self_test',
    ]

    _fields_and_field_types = {
        'power_self_test': 'diagnostic_msgs/DiagnosticArray',
    }

    SLOT_TYPES = (
        rosidl_parser.definition.NamespacedType(['diagnostic_msgs', 'msg'], 'DiagnosticArray'),  # noqa: E501
    )

    def __init__(self, **kwargs):
        assert all('_' + key in self.__slots__ for key in kwargs.keys()), \
            'Invalid arguments passed to constructor: %s' % \
            ', '.join(sorted(k for k in kwargs.keys() if '_' + k not in self.__slots__))
        from diagnostic_msgs.msg import DiagnosticArray
        self.power_self_test = kwargs.get('power_self_test', DiagnosticArray())

    def __repr__(self):
        typename = self.__class__.__module__.split('.')
        typename.pop()
        typename.append(self.__class__.__name__)
        args = []
        for s, t in zip(self.__slots__, self.SLOT_TYPES):
            field = getattr(self, s)
            fieldstr = repr(field)
            # We use Python array type for fields that can be directly stored
            # in them, and "normal" sequences for everything else.  If it is
            # a type that we store in an array, strip off the 'array' portion.
            if (
                isinstance(t, rosidl_parser.definition.AbstractSequence) and
                isinstance(t.value_type, rosidl_parser.definition.BasicType) and
                t.value_type.typename in ['float', 'double', 'int8', 'uint8', 'int16', 'uint16', 'int32', 'uint32', 'int64', 'uint64']
            ):
                if len(field) == 0:
                    fieldstr = '[]'
                else:
                    assert fieldstr.startswith('array(')
                    prefix = "array('X', "
                    suffix = ')'
                    fieldstr = fieldstr[len(prefix):-len(suffix)]
            args.append(s[1:] + '=' + fieldstr)
        return '%s(%s)' % ('.'.join(typename), ', '.join(args))

    def __eq__(self, other):
        if not isinstance(other, self.__class__):
            return False
        if self.power_self_test != other.power_self_test:
            return False
        return True

    @classmethod
    def get_fields_and_field_types(cls):
        from copy import copy
        return copy(cls._fields_and_field_types)

    @builtins.property
    def power_self_test(self):
        """Message field 'power_self_test'."""
        return self._power_self_test

    @power_self_test.setter
    def power_self_test(self, value):
        if __debug__:
            from diagnostic_msgs.msg import DiagnosticArray
            assert \
                isinstance(value, DiagnosticArray), \
                "The 'power_self_test' field must be a sub message of type 'DiagnosticArray'"
        self._power_self_test = value


# Import statements for member types

# already imported above
# import builtins

# already imported above
# import rosidl_parser.definition


class Metaclass_PowerSelfTestSrv_Response(type):
    """Metaclass of message 'PowerSelfTestSrv_Response'."""

    _CREATE_ROS_MESSAGE = None
    _CONVERT_FROM_PY = None
    _CONVERT_TO_PY = None
    _DESTROY_ROS_MESSAGE = None
    _TYPE_SUPPORT = None

    __constants = {
    }

    @classmethod
    def __import_type_support__(cls):
        try:
            from rosidl_generator_py import import_type_support
            module = import_type_support('tita_system_interfaces')
        except ImportError:
            import logging
            import traceback
            logger = logging.getLogger(
                'tita_system_interfaces.srv.PowerSelfTestSrv_Response')
            logger.debug(
                'Failed to import needed modules for type support:\n' +
                traceback.format_exc())
        else:
            cls._CREATE_ROS_MESSAGE = module.create_ros_message_msg__srv__power_self_test_srv__response
            cls._CONVERT_FROM_PY = module.convert_from_py_msg__srv__power_self_test_srv__response
            cls._CONVERT_TO_PY = module.convert_to_py_msg__srv__power_self_test_srv__response
            cls._TYPE_SUPPORT = module.type_support_msg__srv__power_self_test_srv__response
            cls._DESTROY_ROS_MESSAGE = module.destroy_ros_message_msg__srv__power_self_test_srv__response

    @classmethod
    def __prepare__(cls, name, bases, **kwargs):
        # list constant names here so that they appear in the help text of
        # the message class under "Data and other attributes defined here:"
        # as well as populate each message instance
        return {
        }


class PowerSelfTestSrv_Response(metaclass=Metaclass_PowerSelfTestSrv_Response):
    """Message class 'PowerSelfTestSrv_Response'."""

    __slots__ = [
        '_success',
    ]

    _fields_and_field_types = {
        'success': 'boolean',
    }

    SLOT_TYPES = (
        rosidl_parser.definition.BasicType('boolean'),  # noqa: E501
    )

    def __init__(self, **kwargs):
        assert all('_' + key in self.__slots__ for key in kwargs.keys()), \
            'Invalid arguments passed to constructor: %s' % \
            ', '.join(sorted(k for k in kwargs.keys() if '_' + k not in self.__slots__))
        self.success = kwargs.get('success', bool())

    def __repr__(self):
        typename = self.__class__.__module__.split('.')
        typename.pop()
        typename.append(self.__class__.__name__)
        args = []
        for s, t in zip(self.__slots__, self.SLOT_TYPES):
            field = getattr(self, s)
            fieldstr = repr(field)
            # We use Python array type for fields that can be directly stored
            # in them, and "normal" sequences for everything else.  If it is
            # a type that we store in an array, strip off the 'array' portion.
            if (
                isinstance(t, rosidl_parser.definition.AbstractSequence) and
                isinstance(t.value_type, rosidl_parser.definition.BasicType) and
                t.value_type.typename in ['float', 'double', 'int8', 'uint8', 'int16', 'uint16', 'int32', 'uint32', 'int64', 'uint64']
            ):
                if len(field) == 0:
                    fieldstr = '[]'
                else:
                    assert fieldstr.startswith('array(')
                    prefix = "array('X', "
                    suffix = ')'
                    fieldstr = fieldstr[len(prefix):-len(suffix)]
            args.append(s[1:] + '=' + fieldstr)
        return '%s(%s)' % ('.'.join(typename), ', '.join(args))

    def __eq__(self, other):
        if not isinstance(other, self.__class__):
            return False
        if self.success != other.success:
            return False
        return True

    @classmethod
    def get_fields_and_field_types(cls):
        from copy import copy
        return copy(cls._fields_and_field_types)

    @builtins.property
    def success(self):
        """Message field 'success'."""
        return self._success

    @success.setter
    def success(self, value):
        if __debug__:
            assert \
                isinstance(value, bool), \
                "The 'success' field must be of type 'bool'"
        self._success = value


class Metaclass_PowerSelfTestSrv(type):
    """Metaclass of service 'PowerSelfTestSrv'."""

    _TYPE_SUPPORT = None

    @classmethod
    def __import_type_support__(cls):
        try:
            from rosidl_generator_py import import_type_support
            module = import_type_support('tita_system_interfaces')
        except ImportError:
            import logging
            import traceback
            logger = logging.getLogger(
                'tita_system_interfaces.srv.PowerSelfTestSrv')
            logger.debug(
                'Failed to import needed modules for type support:\n' +
                traceback.format_exc())
        else:
            cls._TYPE_SUPPORT = module.type_support_srv__srv__power_self_test_srv

            from tita_system_interfaces.srv import _power_self_test_srv
            if _power_self_test_srv.Metaclass_PowerSelfTestSrv_Request._TYPE_SUPPORT is None:
                _power_self_test_srv.Metaclass_PowerSelfTestSrv_Request.__import_type_support__()
            if _power_self_test_srv.Metaclass_PowerSelfTestSrv_Response._TYPE_SUPPORT is None:
                _power_self_test_srv.Metaclass_PowerSelfTestSrv_Response.__import_type_support__()


class PowerSelfTestSrv(metaclass=Metaclass_PowerSelfTestSrv):
    from tita_system_interfaces.srv._power_self_test_srv import PowerSelfTestSrv_Request as Request
    from tita_system_interfaces.srv._power_self_test_srv import PowerSelfTestSrv_Response as Response

    def __init__(self):
        raise NotImplementedError('Service classes can not be instantiated')
