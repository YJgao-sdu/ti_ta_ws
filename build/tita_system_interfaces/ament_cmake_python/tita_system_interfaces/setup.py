from setuptools import find_packages
from setuptools import setup

setup(
    name='tita_system_interfaces',
    version='0.0.1',
    packages=find_packages(
        include=('tita_system_interfaces', 'tita_system_interfaces.*')),
)
