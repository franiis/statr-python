prefix="Arch-"
now=$(date +"%m_%d_%Y-%H:%M:%S")
filename=$prefix$now
mkdir -p arch/$filename
mv dist/*.whl arch/$filename/
mv dist/*.tar.gz arch/$filename/

# Build package
./build_script.sh

# Create wheel
python setup.py bdist_wheel
# python setup.py sdist - for source distribution 

# Change it to manylinux1 (it maybe wrong)
rename 's/-linux/-manylinux1/' dist/*.whl

# Upload new version
twine upload dist/*
