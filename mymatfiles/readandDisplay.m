function readandDisplay()
% WFDB App Toolbox Demo
%
% Written by Ikaro Silva, 2013
% Last modified: January 10, 2014
% Detailed annotation by Barro: 2017.09.24 marked by %%
%

[~,config]=wfdbloadlib; 
echo on   %% if display the ouput of functions
display('Reading samples ECG signal from MIT-BIH Arrhythmia Database')
N=10000;
[tm,ecg]=rdsamp('mitdb/100',1,N); %Read signal files of WFDB records

display('Reading and plotting annotations (hum  an labels) of QRS complexes performend on the signals')
%by cardiologists.
[ann,type,subtype,chan,num]=rdann('mitdb/100','atr',1,N); %%Read annotation files for WFDB records

[C,L]=wavedec(ecg,4,'haar'); %% the last number in l should be disregarded!
%%[CA,CD] = dwt(ecg, 'haa r');
%%plot(CA); hold on;
%%a4 = appcoef(C,L,'haar',4); %%obtain the approximation coefficients
%%b4 = detcoef(C,L,'haar',4);  %%obtain the detailed coefficients
ecgrecdet = wrcoef('d',C,L,'haar',4);   %%possible innovation!: using approximation coefficients other than detail coefficients
ecgrecapp = wrcoef('a',C,L,'haar',4); 
plot(tm(1:N),ecg(1:N),'b',tm(1:N),ecgrecdet(1:N),'g',tm(1:N),ecgrecapp(1:N),'r');
%**************************second step:modulus maxima pair identification(MMPI)************************************
% data structure: peak[n],covering all modulus maxima:noise and normal;Npeak,Ppeak;THN,THP
% 2.1 extract modulus maxima line
Peak = zeros(1,N); %%note: if zeros(n), which designates a n*n 2-D matrix!
for i=2:N-1
   cond1 = ecgrecdet(i)<ecgrecdet(i+1)&ecgrecdet(i)<=ecgrecdet(i-1);
   cond2 = ecgrecdet(i)>ecgrecdet(i+1)&ecgrecdet(i)>=ecgrecdet(i-1);
    if(cond1||cond2)
       Peak(i) = ecgrecdet(i); %% peak is the input of second stage
    end
end
% transition: create a structure and save it in a MAT-file
var.time = 1:N;
var.signals.values = Peak;
var.signals.dimensions = 1;
var.signals.label = 'var';
save var.mat var
% 2.2 decision state machine£ºsee stateflow
%Please waiting.....
%**************************third step:R wave Position Modification module(abbr:RPM)************************************
%input: a vector storing the appro position of every single Rwave
%output: a vector within the accurate position of every single Rwave
%peakPositionAppr, peakPositionAccu
for i=1:length(peakPositionAppr) 
    p = peakPositionAppr(i);
    
end


%right outcome
%Plot 2D version of signal and labels
% figure
% plot(tm(1:N),ecg(1:N));hold on;grid on  %%ecg£ºamplitude;tm£ºtime points (unevenly spaced)
% plot(tm(ann(ann<N)+1),ecg(ann(ann<N)+1),'ro'); %%mark the qrs complex






%%now i am unwilling to know of 3D version1

% %Stack the ECG signals based on the labeled QRSs
% display('Ploting 3D version of signal and labels')
% [RR,tms]=ann2rr('mitdb/100','atr',N); %%Extract a list of intervals from an annotation file
% delay=round(0.1/tm(2));
% M=length(RR);
% offset=0.3;
% stack=zeros(M,min(RR))+NaN;
% qrs=zeros(M,2)+NaN;
% for m=1:M
%     stack(m,1:min(RR)+1)=ecg(tms(m)-delay:tms(m)+min(RR)-delay);
%     qrs(m,:)=[delay+1 ecg(tms(m))];
% end
% 
% %Generate plot inspired by
% %Clifford GD, Azuaje F, McSharry PE, editors.
% %Advanced Methods and Tools for ECG Analysis.
% %1st ed., Norwood, MA, USA: Artech House; 2006. (Engineering in Medicine and Biology; 1).
% figure
% [X,Y] = meshgrid(1:min(RR)+1,1:M);
% surf(Y,X,stack);hold on;grid on
% shading interp
% plot3(1:M,qrs(:,1),qrs(:,2)+offset,'go-','MarkerFaceColor','g')
% view(120, 30);
% axis off
% 
% %Generate plot inspired by
% % Samenie et al
% % "Filtering Noisy ECG Signals Using Extended Kalman Filter Based on a
% % Modified Dynamic ECG Model"
% % Computers in Cardiology, 2005
% figure
% stack=stack';
% stack=stack(:)+[0:length(stack(:))-1]'.*0.0005;
% theta=linspace(0,M*2*pi,length(stack));
% x=sin(theta);y=cos(theta);
% plot3(x,y,stack,'b')
% grid on
% axis off
% 
% %Display information about databases availabe in PhysioNet
% fprintf('**Querying PhysioNet for available databases...\n')
% db_list=physionetdb;
% db_size=length(db_list);
% fprintf(['\tYou currently have access to ' num2str(db_size) ' databases for download in PhysioNet (type ''help physionetdb'' for more info)!\n'])
% 
% display('Demoing finished !!')
% display('For more information about the toolbox, type ''wfdb'' at the command prompt.')
% echo off
