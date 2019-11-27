module load gcc
module unload gcc
rm -r dist
rm -r build
python bundle_builder.py wheel
cd dist
python -m pip install --user --force-reinstall Clipper_Python-0.2-cp37-cp37m-linux_x86_64.whl
