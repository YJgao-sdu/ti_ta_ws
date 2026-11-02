# generated from rosidl_generator_py/resource/_idl.py.em
# with input from locomotion_msgs:msg/PlanCommands.idl
# generated code does not contain a copyright notice


# Import statements for member types

# Member 'joint_positions'
# Member 'joint_velocities'
# Member 'joint_torques'
import array  # noqa: E402, I100

import builtins  # noqa: E402, I100

import math  # noqa: E402, I100

import rosidl_parser.definition  # noqa: E402, I100


class Metaclass_PlanCommands(type):
    """Metaclass of message 'PlanCommands'."""

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
            module = import_type_support('locomotion_msgs')
        except ImportError:
            import logging
            import traceback
            logger = logging.getLogger(
                'locomotion_msgs.msg.PlanCommands')
            logger.debug(
                'Failed to import needed modules for type support:\n' +
                traceback.format_exc())
        else:
            cls._CREATE_ROS_MESSAGE = module.create_ros_message_msg__msg__plan_commands
            cls._CONVERT_FROM_PY = module.convert_from_py_msg__msg__plan_commands
            cls._CONVERT_TO_PY = module.convert_to_py_msg__msg__plan_commands
            cls._TYPE_SUPPORT = module.type_support_msg__msg__plan_commands
            cls._DESTROY_ROS_MESSAGE = module.destroy_ros_message_msg__msg__plan_commands

            from geometry_msgs.msg import Vector3
            if Vector3.__class__._TYPE_SUPPORT is None:
                Vector3.__class__.__import_type_support__()

            from std_msgs.msg import Header
            if Header.__class__._TYPE_SUPPORT is None:
                Header.__class__.__import_type_support__()

    @classmethod
    def __prepare__(cls, name, bases, **kwargs):
        # list constant names here so that they appear in the help text of
        # the message class under "Data and other attributes defined here:"
        # as well as populate each message instance
        return {
        }


class PlanCommands(metaclass=Metaclass_PlanCommands):
    """Message class 'PlanCommands'."""

    __slots__ = [
        '_header',
        '_fsm_state_name',
        '_twist_linear',
        '_twist_linear_int',
        '_twist_angular',
        '_twist_angular_int',
        '_pose_position',
        '_pose_position_dot',
        '_pose_rpy',
        '_pose_rpy_dot',
        '_two_wheel_distance',
        '_two_wheel_distance_dot',
        '_joint_positions',
        '_joint_velocities',
        '_joint_torques',
    ]

    _fields_and_field_types = {
        'header': 'std_msgs/Header',
        'fsm_state_name': 'string',
        'twist_linear': 'geometry_msgs/Vector3',
        'twist_linear_int': 'geometry_msgs/Vector3',
        'twist_angular': 'geometry_msgs/Vector3',
        'twist_angular_int': 'geometry_msgs/Vector3',
        'pose_position': 'geometry_msgs/Vector3',
        'pose_position_dot': 'geometry_msgs/Vector3',
        'pose_rpy': 'geometry_msgs/Vector3',
        'pose_rpy_dot': 'geometry_msgs/Vector3',
        'two_wheel_distance': 'double',
        'two_wheel_distance_dot': 'double',
        'joint_positions': 'sequence<double>',
        'joint_velocities': 'sequence<double>',
        'joint_torques': 'sequence<double>',
    }

    SLOT_TYPES = (
        rosidl_parser.definition.NamespacedType(['std_msgs', 'msg'], 'Header'),  # noqa: E501
        rosidl_parser.definition.UnboundedString(),  # noqa: E501
        rosidl_parser.definition.NamespacedType(['geometry_msgs', 'msg'], 'Vector3'),  # noqa: E501
        rosidl_parser.definition.NamespacedType(['geometry_msgs', 'msg'], 'Vector3'),  # noqa: E501
        rosidl_parser.definition.NamespacedType(['geometry_msgs', 'msg'], 'Vector3'),  # noqa: E501
        rosidl_parser.definition.NamespacedType(['geometry_msgs', 'msg'], 'Vector3'),  # noqa: E501
        rosidl_parser.definition.NamespacedType(['geometry_msgs', 'msg'], 'Vector3'),  # noqa: E501
        rosidl_parser.definition.NamespacedType(['geometry_msgs', 'msg'], 'Vector3'),  # noqa: E501
        rosidl_parser.definition.NamespacedType(['geometry_msgs', 'msg'], 'Vector3'),  # noqa: E501
        rosidl_parser.definition.NamespacedType(['geometry_msgs', 'msg'], 'Vector3'),  # noqa: E501
        rosidl_parser.definition.BasicType('double'),  # noqa: E501
        rosidl_parser.definition.BasicType('double'),  # noqa: E501
        rosidl_parser.definition.UnboundedSequence(rosidl_parser.definition.BasicType('double')),  # noqa: E501
        rosidl_parser.definition.UnboundedSequence(rosidl_parser.definition.BasicType('double')),  # noqa: E501
        rosidl_parser.definition.UnboundedSequence(rosidl_parser.definition.BasicType('double')),  # noqa: E501
    )

    def __init__(self, **kwargs):
        assert all('_' + key in self.__slots__ for key in kwargs.keys()), \
            'Invalid arguments passed to constructor: %s' % \
            ', '.join(sorted(k for k in kwargs.keys() if '_' + k not in self.__slots__))
        from std_msgs.msg import Header
        self.header = kwargs.get('header', Header())
        self.fsm_state_name = kwargs.get('fsm_state_name', str())
        from geometry_msgs.msg import Vector3
        self.twist_linear = kwargs.get('twist_linear', Vector3())
        from geometry_msgs.msg import Vector3
        self.twist_linear_int = kwargs.get('twist_linear_int', Vector3())
        from geometry_msgs.msg import Vector3
        self.twist_angular = kwargs.get('twist_angular', Vector3())
        from geometry_msgs.msg import Vector3
        self.twist_angular_int = kwargs.get('twist_angular_int', Vector3())
        from geometry_msgs.msg import Vector3
        self.pose_position = kwargs.get('pose_position', Vector3())
        from geometry_msgs.msg import Vector3
        self.pose_position_dot = kwargs.get('pose_position_dot', Vector3())
        from geometry_msgs.msg import Vector3
        self.pose_rpy = kwargs.get('pose_rpy', Vector3())
        from geometry_msgs.msg import Vector3
        self.pose_rpy_dot = kwargs.get('pose_rpy_dot', Vector3())
        self.two_wheel_distance = kwargs.get('two_wheel_distance', float())
        self.two_wheel_distance_dot = kwargs.get('two_wheel_distance_dot', float())
        self.joint_positions = array.array('d', kwargs.get('joint_positions', []))
        self.joint_velocities = array.array('d', kwargs.get('joint_velocities', []))
        self.joint_torques = array.array('d', kwargs.get('joint_torques', []))

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
        if self.header != other.header:
            return False
        if self.fsm_state_name != other.fsm_state_name:
            return False
        if self.twist_linear != other.twist_linear:
            return False
        if self.twist_linear_int != other.twist_linear_int:
            return False
        if self.twist_angular != other.twist_angular:
            return False
        if self.twist_angular_int != other.twist_angular_int:
            return False
        if self.pose_position != other.pose_position:
            return False
        if self.pose_position_dot != other.pose_position_dot:
            return False
        if self.pose_rpy != other.pose_rpy:
            return False
        if self.pose_rpy_dot != other.pose_rpy_dot:
            return False
        if self.two_wheel_distance != other.two_wheel_distance:
            return False
        if self.two_wheel_distance_dot != other.two_wheel_distance_dot:
            return False
        if self.joint_positions != other.joint_positions:
            return False
        if self.joint_velocities != other.joint_velocities:
            return False
        if self.joint_torques != other.joint_torques:
            return False
        return True

    @classmethod
    def get_fields_and_field_types(cls):
        from copy import copy
        return copy(cls._fields_and_field_types)

    @builtins.property
    def header(self):
        """Message field 'header'."""
        return self._header

    @header.setter
    def header(self, value):
        if __debug__:
            from std_msgs.msg import Header
            assert \
                isinstance(value, Header), \
                "The 'header' field must be a sub message of type 'Header'"
        self._header = value

    @builtins.property
    def fsm_state_name(self):
        """Message field 'fsm_state_name'."""
        return self._fsm_state_name

    @fsm_state_name.setter
    def fsm_state_name(self, value):
        if __debug__:
            assert \
                isinstance(value, str), \
                "The 'fsm_state_name' field must be of type 'str'"
        self._fsm_state_name = value

    @builtins.property
    def twist_linear(self):
        """Message field 'twist_linear'."""
        return self._twist_linear

    @twist_linear.setter
    def twist_linear(self, value):
        if __debug__:
            from geometry_msgs.msg import Vector3
            assert \
                isinstance(value, Vector3), \
                "The 'twist_linear' field must be a sub message of type 'Vector3'"
        self._twist_linear = value

    @builtins.property
    def twist_linear_int(self):
        """Message field 'twist_linear_int'."""
        return self._twist_linear_int

    @twist_linear_int.setter
    def twist_linear_int(self, value):
        if __debug__:
            from geometry_msgs.msg import Vector3
            assert \
                isinstance(value, Vector3), \
                "The 'twist_linear_int' field must be a sub message of type 'Vector3'"
        self._twist_linear_int = value

    @builtins.property
    def twist_angular(self):
        """Message field 'twist_angular'."""
        return self._twist_angular

    @twist_angular.setter
    def twist_angular(self, value):
        if __debug__:
            from geometry_msgs.msg import Vector3
            assert \
                isinstance(value, Vector3), \
                "The 'twist_angular' field must be a sub message of type 'Vector3'"
        self._twist_angular = value

    @builtins.property
    def twist_angular_int(self):
        """Message field 'twist_angular_int'."""
        return self._twist_angular_int

    @twist_angular_int.setter
    def twist_angular_int(self, value):
        if __debug__:
            from geometry_msgs.msg import Vector3
            assert \
                isinstance(value, Vector3), \
                "The 'twist_angular_int' field must be a sub message of type 'Vector3'"
        self._twist_angular_int = value

    @builtins.property
    def pose_position(self):
        """Message field 'pose_position'."""
        return self._pose_position

    @pose_position.setter
    def pose_position(self, value):
        if __debug__:
            from geometry_msgs.msg import Vector3
            assert \
                isinstance(value, Vector3), \
                "The 'pose_position' field must be a sub message of type 'Vector3'"
        self._pose_position = value

    @builtins.property
    def pose_position_dot(self):
        """Message field 'pose_position_dot'."""
        return self._pose_position_dot

    @pose_position_dot.setter
    def pose_position_dot(self, value):
        if __debug__:
            from geometry_msgs.msg import Vector3
            assert \
                isinstance(value, Vector3), \
                "The 'pose_position_dot' field must be a sub message of type 'Vector3'"
        self._pose_position_dot = value

    @builtins.property
    def pose_rpy(self):
        """Message field 'pose_rpy'."""
        return self._pose_rpy

    @pose_rpy.setter
    def pose_rpy(self, value):
        if __debug__:
            from geometry_msgs.msg import Vector3
            assert \
                isinstance(value, Vector3), \
                "The 'pose_rpy' field must be a sub message of type 'Vector3'"
        self._pose_rpy = value

    @builtins.property
    def pose_rpy_dot(self):
        """Message field 'pose_rpy_dot'."""
        return self._pose_rpy_dot

    @pose_rpy_dot.setter
    def pose_rpy_dot(self, value):
        if __debug__:
            from geometry_msgs.msg import Vector3
            assert \
                isinstance(value, Vector3), \
                "The 'pose_rpy_dot' field must be a sub message of type 'Vector3'"
        self._pose_rpy_dot = value

    @builtins.property
    def two_wheel_distance(self):
        """Message field 'two_wheel_distance'."""
        return self._two_wheel_distance

    @two_wheel_distance.setter
    def two_wheel_distance(self, value):
        if __debug__:
            assert \
                isinstance(value, float), \
                "The 'two_wheel_distance' field must be of type 'float'"
            assert not (value < -1.7976931348623157e+308 or value > 1.7976931348623157e+308) or math.isinf(value), \
                "The 'two_wheel_distance' field must be a double in [-1.7976931348623157e+308, 1.7976931348623157e+308]"
        self._two_wheel_distance = value

    @builtins.property
    def two_wheel_distance_dot(self):
        """Message field 'two_wheel_distance_dot'."""
        return self._two_wheel_distance_dot

    @two_wheel_distance_dot.setter
    def two_wheel_distance_dot(self, value):
        if __debug__:
            assert \
                isinstance(value, float), \
                "The 'two_wheel_distance_dot' field must be of type 'float'"
            assert not (value < -1.7976931348623157e+308 or value > 1.7976931348623157e+308) or math.isinf(value), \
                "The 'two_wheel_distance_dot' field must be a double in [-1.7976931348623157e+308, 1.7976931348623157e+308]"
        self._two_wheel_distance_dot = value

    @builtins.property
    def joint_positions(self):
        """Message field 'joint_positions'."""
        return self._joint_positions

    @joint_positions.setter
    def joint_positions(self, value):
        if isinstance(value, array.array):
            assert value.typecode == 'd', \
                "The 'joint_positions' array.array() must have the type code of 'd'"
            self._joint_positions = value
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
                 all(isinstance(v, float) for v in value) and
                 all(not (val < -1.7976931348623157e+308 or val > 1.7976931348623157e+308) or math.isinf(val) for val in value)), \
                "The 'joint_positions' field must be a set or sequence and each value of type 'float' and each double in [-179769313486231570814527423731704356798070567525844996598917476803157260780028538760589558632766878171540458953514382464234321326889464182768467546703537516986049910576551282076245490090389328944075868508455133942304583236903222948165808559332123348274797826204144723168738177180919299881250404026184124858368.000000, 179769313486231570814527423731704356798070567525844996598917476803157260780028538760589558632766878171540458953514382464234321326889464182768467546703537516986049910576551282076245490090389328944075868508455133942304583236903222948165808559332123348274797826204144723168738177180919299881250404026184124858368.000000]"
        self._joint_positions = array.array('d', value)

    @builtins.property
    def joint_velocities(self):
        """Message field 'joint_velocities'."""
        return self._joint_velocities

    @joint_velocities.setter
    def joint_velocities(self, value):
        if isinstance(value, array.array):
            assert value.typecode == 'd', \
                "The 'joint_velocities' array.array() must have the type code of 'd'"
            self._joint_velocities = value
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
                 all(isinstance(v, float) for v in value) and
                 all(not (val < -1.7976931348623157e+308 or val > 1.7976931348623157e+308) or math.isinf(val) for val in value)), \
                "The 'joint_velocities' field must be a set or sequence and each value of type 'float' and each double in [-179769313486231570814527423731704356798070567525844996598917476803157260780028538760589558632766878171540458953514382464234321326889464182768467546703537516986049910576551282076245490090389328944075868508455133942304583236903222948165808559332123348274797826204144723168738177180919299881250404026184124858368.000000, 179769313486231570814527423731704356798070567525844996598917476803157260780028538760589558632766878171540458953514382464234321326889464182768467546703537516986049910576551282076245490090389328944075868508455133942304583236903222948165808559332123348274797826204144723168738177180919299881250404026184124858368.000000]"
        self._joint_velocities = array.array('d', value)

    @builtins.property
    def joint_torques(self):
        """Message field 'joint_torques'."""
        return self._joint_torques

    @joint_torques.setter
    def joint_torques(self, value):
        if isinstance(value, array.array):
            assert value.typecode == 'd', \
                "The 'joint_torques' array.array() must have the type code of 'd'"
            self._joint_torques = value
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
                 all(isinstance(v, float) for v in value) and
                 all(not (val < -1.7976931348623157e+308 or val > 1.7976931348623157e+308) or math.isinf(val) for val in value)), \
                "The 'joint_torques' field must be a set or sequence and each value of type 'float' and each double in [-179769313486231570814527423731704356798070567525844996598917476803157260780028538760589558632766878171540458953514382464234321326889464182768467546703537516986049910576551282076245490090389328944075868508455133942304583236903222948165808559332123348274797826204144723168738177180919299881250404026184124858368.000000, 179769313486231570814527423731704356798070567525844996598917476803157260780028538760589558632766878171540458953514382464234321326889464182768467546703537516986049910576551282076245490090389328944075868508455133942304583236903222948165808559332123348274797826204144723168738177180919299881250404026184124858368.000000]"
        self._joint_torques = array.array('d', value)
