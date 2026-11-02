from setuptools import find_packages
from setuptools import setup

setup(
    name='tita_locomotion_interfaces',
    version='0.0.1',
    packages=find_packages(
        include=('tita_locomotion_interfaces', 'tita_locomotion_interfaces.*')),
)
