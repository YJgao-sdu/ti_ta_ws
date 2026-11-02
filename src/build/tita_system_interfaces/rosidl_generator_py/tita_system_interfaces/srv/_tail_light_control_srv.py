# generated from rosidl_generator_py/resource/_idl.py.em
# with input from tita_system_interfaces:srv/TailLightControlSrv.idl
# generated code does not contain a copyright notice


# Import statements for member types

import builtins  # noqa: E402, I100

# Member 'light_rgbl_value'
import numpy  # noqa: E402, I100

import rosidl_parser.definition  # noqa: E402, I100


class Metaclass_TailLightControlSrv_Request(type):
    """Metaclass of message 'TailLightControlSrv_Request'."""

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
                'tita_system_interfaces.srv.TailLightControlSrv_Request')
            logger.debug(
                'Failed to import needed modules for type support:\n' +
                traceback.format_exc())
        else:
            cls._CREATE_ROS_MESSAGE = module.create_ros_message_msg__srv__tail_light_control_srv__request
            cls._CONVERT_FROM_PY = module.convert_from_py_msg__srv__tail_light_control_srv__request
            cls._CONVERT_TO_PY = module.convert_to_py_msg__srv__tail_light_control_srv__request
            cls._TYPE_SUPPORT = module.type_support_msg__srv__tail_light_control_srv__request
            cls._DESTROY_ROS_MESSAGE = module.destroy_ros_message_msg__srv__tail_light_control_srv__request

    @classmethod
    def __prepare__(cls, name, bases, **kwargs):
        # list constant names here so that they appear in the help text of
        # the message class under "Data and other attributes defined here:"
        # as well as populate each message instance
        return {
        }


class TailLightControlSrv_Request(metaclass=Metaclass_TailLightControlSrv_Request):
    """Message class 'TailLightControlSrv_Request'."""

    __slots__ = [
        '_is_control',
        '_light_rgbl_value',
    ]

    _fields_and_field_types = {
        'is_control': 'boolean',
        'light_rgbl_value': 'uint32[36]',
    }

    SLOT_TYPES = (
        rosidl_parser.definition.BasicType('boolean'),  # noqa: E501
        rosidl_parser.definition.Array(rosidl_parser.definition.BasicType('uint32'), 36),  # noqa: E501
    )

    def __init__(self, **kwargs):
        assert all('_' + key in self.__slots__ for key in kwargs.keys()), \
            'Invalid arguments passed to constructor: %s' % \
            ', '.join(sorted(k for k in kwargs.keys() if '_' + k not in self.__slots__))
        self.is_control = kwargs.get('is_control', bool())
        if 'light_rgbl_value' not in kwargs:
            self.light_rgbl_value = numpy.zeros(36, dtype=numpy.uint32)
        else:
            self.light_rgbl_value = numpy.array(kwargs.get('light_rgbl_value'), dtype=numpy.uint32)
            assert self.light_rgbl_value.shape == (36, )

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
        if self.is_control != other.is_control:
            return False
        if all(self.light_rgbl_value != other.light_rgbl_value):
            return False
        return True

    @classmethod
    def get_fields_and_field_types(cls):
        from copy import copy
        return copy(cls._fields_and_field_types)

    @builtins.property
    def is_control(self):
        """Message field 'is_control'."""
        return self._is_control

    @is_control.setter
    def is_control(self, value):
        if __debug__:
            assert \
                isinstance(value, bool), \
                "The 'is_control' field must be of type 'bool'"
        self._is_control = value

    @builtins.property
    def light_rgbl_value(self):
        """Message field 'light_rgbl_value'."""
        return self._light_rgbl_value

    @light_rgbl_value.setter
    def light_rgbl_value(self, value):
        if isinstance(value, numpy.ndarray):
            assert value.dtype == numpy.uint32, \
                "The 'light_rgbl_value' numpy.ndarray() must have the dtype of 'numpy.uint32'"
            assert value.size == 36, \
                "The 'light_rgbl_value' numpy.ndarray() must have a size of 36"
            self._light_rgbl_value = value
            return
        if __debug__:
            from collections.abc import Sequence
            from collections.abc import Set
            from collections import UserList
            from collections import UserString
            assert \
                ((isinstance(value, Sequence) or
                  isinstance(value, Set) or
                  isinstance(value, UserList)) and
                 not isinstance(value, str) and
                 not isinstance(value, UserString) and
                 len(value) == 36 and
                 all(isinstance(v, int) for v in value) and
                 all(val >= 0 and val < 4294967296 for val in value)), \
                "The 'light_rgbl_value' field must be a set or sequence with length 36 and each value of type 'int' and each unsigned integer in [0, 4294967295]"
        self._light_rgbl_value = numpy.array(value, dtype=numpy.uint32)


# Import statements for member types

# already imported above
# import builtins

# already imported above
# import rosidl_parser.definition


class Metaclass_TailLightControlSrv_Response(type):
    """Metaclass of message 'TailLightControlSrv_Response'."""

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
                'tita_system_interfaces.srv.TailLightControlSrv_Response')
            logger.debug(
                'Failed to import needed modules for type support:\n' +
                traceback.format_exc())
        else:
            cls._CREATE_ROS_MESSAGE = module.create_ros_message_msg__srv__tail_light_control_srv__response
            cls._CONVERT_FROM_PY = module.convert_from_py_msg__srv__tail_light_control_srv__response
            cls._CONVERT_TO_PY = module.convert_to_py_msg__srv__tail_light_control_srv__response
            cls._TYPE_SUPPORT = module.type_support_msg__srv__tail_light_control_srv__response
            cls._DESTROY_ROS_MESSAGE = module.destroy_ros_message_msg__srv__tail_light_control_srv__response

    @classmethod
    def __prepare__(cls, name, bases, **kwargs):
        # list constant names here so that they appear in the help text of
        # the message class under "Data and other attributes defined here:"
        # as well as populate each message instance
        return {
        }


class TailLightControlSrv_Response(metaclass=Metaclass_TailLightControlSrv_Response):
    """Message class 'TailLightControlSrv_Response'."""

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


class Metaclass_TailLightControlSrv(type):
    """Metaclass of service 'TailLightControlSrv'."""

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
                'tita_system_interfaces.srv.TailLightControlSrv')
            logger.debug(
                'Failed to import needed modules for type support:\n' +
                traceback.format_exc())
        else:
            cls._TYPE_SUPPORT = module.type_support_srv__srv__tail_light_control_srv

            from tita_system_interfaces.srv import _tail_light_control_srv
            if _tail_light_control_srv.Metaclass_TailLightControlSrv_Request._TYPE_SUPPORT is None:
                _tail_light_control_srv.Metaclass_TailLightControlSrv_Request.__import_type_support__()
            if _tail_light_control_srv.Metaclass_TailLightControlSrv_Response._TYPE_SUPPORT is None:
                _tail_light_control_srv.Metaclass_TailLightControlSrv_Response.__import_type_support__()


class TailLightControlSrv(metaclass=Metaclass_TailLightControlSrv):
    from tita_system_interfaces.srv._tail_light_control_srv import TailLightControlSrv_Request as Request
    from tita_system_interfaces.srv._tail_light_control_srv import TailLightControlSrv_Response as Response

    def __init__(self):
        raise NotImplementedError('Service classes can not be instantiated')
