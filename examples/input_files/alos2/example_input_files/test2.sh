export OMP_NUM_THREADS=4
export CUDA_VISIBLE_DEVICES=6

#scansar-scansar_burst
cd scansar-scansar_burst/1
alos2burstApp.py --steps
cd ../../

cd scansar-scansar_burst/2
alos2burstApp.py --steps
cd ../../

cd scansar-scansar_burst/3
alos2burstApp.py --steps
cd ../../

cd scansar-scansar_burst/4
alos2burstApp.py --steps
cd ../../
