from setuptools import find_packages
from setuptools import setup

setup(
    name='locomotion_msgs',
    version='0.0.0',
    packages=find_packages(
        include=('locomotion_msgs', 'locomotion_msgs.*')),
)
