# generated from rosidl_generator_py/resource/_idl.py.em
# with input from tita_perception_interfaces:srv/ObjectDetection.idl
# generated code does not contain a copyright notice


# Import statements for member types

import builtins  # noqa: E402, I100

import rosidl_parser.definition  # noqa: E402, I100


class Metaclass_ObjectDetection_Request(type):
    """Metaclass of message 'ObjectDetection_Request'."""

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
            module = import_type_support('tita_perception_interfaces')
        except ImportError:
            import logging
            import traceback
            logger = logging.getLogger(
                'tita_perception_interfaces.srv.ObjectDetection_Request')
            logger.debug(
                'Failed to import needed modules for type support:\n' +
                traceback.format_exc())
        else:
            cls._CREATE_ROS_MESSAGE = module.create_ros_message_msg__srv__object_detection__request
            cls._CONVERT_FROM_PY = module.convert_from_py_msg__srv__object_detection__request
            cls._CONVERT_TO_PY = module.convert_to_py_msg__srv__object_detection__request
            cls._TYPE_SUPPORT = module.type_support_msg__srv__object_detection__request
            cls._DESTROY_ROS_MESSAGE = module.destroy_ros_message_msg__srv__object_detection__request

            from sensor_msgs.msg import Image
            if Image.__class__._TYPE_SUPPORT is None:
                Image.__class__.__import_type_support__()

    @classmethod
    def __prepare__(cls, name, bases, **kwargs):
        # list constant names here so that they appear in the help text of
        # the message class under "Data and other attributes defined here:"
        # as well as populate each message instance
        return {
        }


class ObjectDetection_Request(metaclass=Metaclass_ObjectDetection_Request):
    """Message class 'ObjectDetection_Request'."""

    __slots__ = [
        '_image',
    ]

    _fields_and_field_types = {
        'image': 'sensor_msgs/Image',
    }

    SLOT_TYPES = (
        rosidl_parser.definition.NamespacedType(['sensor_msgs', 'msg'], 'Image'),  # noqa: E501
    )

    def __init__(self, **kwargs):
        assert all('_' + key in self.__slots__ for key in kwargs.keys()), \
            'Invalid arguments passed to constructor: %s' % \
            ', '.join(sorted(k for k in kwargs.keys() if '_' + k not in self.__slots__))
        from sensor_msgs.msg import Image
        self.image = kwargs.get('image', Image())

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
        if self.image != other.image:
            return False
        return True

    @classmethod
    def get_fields_and_field_types(cls):
        from copy import copy
        return copy(cls._fields_and_field_types)

    @builtins.property
    def image(self):
        """Message field 'image'."""
        return self._image

    @image.setter
    def image(self, value):
        if __debug__:
            from sensor_msgs.msg import Image
            assert \
                isinstance(value, Image), \
                "The 'image' field must be a sub message of type 'Image'"
        self._image = value


# Import statements for member types

# already imported above
# import builtins

# already imported above
# import rosidl_parser.definition


class Metaclass_ObjectDetection_Response(type):
    """Metaclass of message 'ObjectDetection_Response'."""

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
            module = import_type_support('tita_perception_interfaces')
        except ImportError:
            import logging
            import traceback
            logger = logging.getLogger(
                'tita_perception_interfaces.srv.ObjectDetection_Response')
            logger.debug(
                'Failed to import needed modules for type support:\n' +
                traceback.format_exc())
        else:
            cls._CREATE_ROS_MESSAGE = module.create_ros_message_msg__srv__object_detection__response
            cls._CONVERT_FROM_PY = module.convert_from_py_msg__srv__object_detection__response
            cls._CONVERT_TO_PY = module.convert_to_py_msg__srv__object_detection__response
            cls._TYPE_SUPPORT = module.type_support_msg__srv__object_detection__response
            cls._DESTROY_ROS_MESSAGE = module.destroy_ros_message_msg__srv__object_detection__response

            from tita_perception_interfaces.msg import BoundingBoxArray
            if BoundingBoxArray.__class__._TYPE_SUPPORT is None:
                BoundingBoxArray.__class__.__import_type_support__()

    @classmethod
    def __prepare__(cls, name, bases, **kwargs):
        # list constant names here so that they appear in the help text of
        # the message class under "Data and other attributes defined here:"
        # as well as populate each message instance
        return {
        }


class ObjectDetection_Response(metaclass=Metaclass_ObjectDetection_Response):
    """Message class 'ObjectDetection_Response'."""

    __slots__ = [
        '_result',
    ]

    _fields_and_field_types = {
        'result': 'tita_perception_interfaces/BoundingBoxArray',
    }

    SLOT_TYPES = (
        rosidl_parser.definition.NamespacedType(['tita_perception_interfaces', 'msg'], 'BoundingBoxArray'),  # noqa: E501
    )

    def __init__(self, **kwargs):
        assert all('_' + key in self.__slots__ for key in kwargs.keys()), \
            'Invalid arguments passed to constructor: %s' % \
            ', '.join(sorted(k for k in kwargs.keys() if '_' + k not in self.__slots__))
        from tita_perception_interfaces.msg import BoundingBoxArray
        self.result = kwargs.get('result', BoundingBoxArray())

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
        if self.result != other.result:
            return False
        return True

    @classmethod
    def get_fields_and_field_types(cls):
        from copy import copy
        return copy(cls._fields_and_field_types)

    @builtins.property
    def result(self):
        """Message field 'result'."""
        return self._result

    @result.setter
    def result(self, value):
        if __debug__:
            from tita_perception_interfaces.msg import BoundingBoxArray
            assert \
                isinstance(value, BoundingBoxArray), \
                "The 'result' field must be a sub message of type 'BoundingBoxArray'"
        self._result = value


class Metaclass_ObjectDetection(type):
    """Metaclass of service 'ObjectDetection'."""

    _TYPE_SUPPORT = None

    @classmethod
    def __import_type_support__(cls):
        try:
            from rosidl_generator_py import import_type_support
            module = import_type_support('tita_perception_interfaces')
        except ImportError:
            import logging
            import traceback
            logger = logging.getLogger(
                'tita_perception_interfaces.srv.ObjectDetection')
            logger.debug(
                'Failed to import needed modules for type support:\n' +
                traceback.format_exc())
        else:
            cls._TYPE_SUPPORT = module.type_support_srv__srv__object_detection

            from tita_perception_interfaces.srv import _object_detection
            if _object_detection.Metaclass_ObjectDetection_Request._TYPE_SUPPORT is None:
                _object_detection.Metaclass_ObjectDetection_Request.__import_type_support__()
            if _object_detection.Metaclass_ObjectDetection_Response._TYPE_SUPPORT is None:
                _object_detection.Metaclass_ObjectDetection_Response.__import_type_support__()


class ObjectDetection(metaclass=Metaclass_ObjectDetection):
    from tita_perception_interfaces.srv._object_detection import ObjectDetection_Request as Request
    from tita_perception_interfaces.srv._object_detection import ObjectDetection_Response as Response

    def __init__(self):
        raise NotImplementedError('Service classes can not be instantiated')
