TEMPLATE = subdirs  
CONFIG += ordered static

message(University of Calgary Solar Car Team Helios Hermes)

SUBDIRS = \
   InfrastructureLayer \
   DataLayer \
   CommunicationLayer \
   BusinessLayer \
   # Tests \
   SchulichHeliosHermes
